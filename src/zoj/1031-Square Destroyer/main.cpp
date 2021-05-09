#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

// the puzzle for each case.
struct puzzle
{
	int n = 0;
	int total_squares = 0;
	int total_sticks = 0;
	ull square_mask = 0;
	vector<ull> stick_square_bitmap;

	void initialize(int n)
	{
		this->n = n;

		// total sticks.
		total_sticks = n * (n + 1) * 2;

		// initiate the mapping relationship between the sticks and squares.
		stick_square_bitmap.clear();

		for (int i = 0; i < total_sticks; i++) { stick_square_bitmap.push_back((ull)0); }

		// total squares
		total_squares = 0;
		int square_index = 0;
		for (int square_size = 1; square_size <= n; square_size++)
		{
			int square_line_count = n - square_size + 1;
			int this_square_count = square_line_count * square_line_count;

			for (int square_local_index = 0; square_local_index < this_square_count; square_local_index++)
			{
				int square_global_index = square_local_index + total_squares;
				ull square_bit = ((ull)1) << square_global_index;

				auto relative_sticks = get_square_relative_sticks(n, square_size, square_line_count, square_local_index);

				for (int stick_index : relative_sticks)
				{
					stick_square_bitmap[stick_index] |= square_bit;
				}
			}

			total_squares += this_square_count;
		}

		// a mask whose lower squares bits are 1.
		square_mask = ~(~((ull)0) << total_squares);
	}

	vector<int> get_square_relative_sticks(int n, int square_size, int square_line_count, int square_local_index)
	{
		vector<int> sticks;
		int square_x = square_local_index % square_line_count;
		int square_y = square_local_index / square_line_count;

		vector<int> line_start(4);
		vector<int> line_step(4);

		// top line:
		// skipped y lines, and offset is x
		line_start[0] = (n + n + 1) * square_y + square_x;
		// step is 1
		line_step[0] = 1;

		// bottom line:
		// skipped y + square_size lines, and offset is x
		line_start[1] = (n + n + 1) * (square_y + square_size) + square_x;
		// step is 1
		line_step[1] = 1;

		// left line:
		// skipped y lines and n edges, and offset is x
		line_start[2] = (n + n + 1) * square_y + n + square_x;
		// step is one line.
		line_step[2] = n + n + 1;

		// right line:
		// skipped y lines and n edges, and offset is x + square_size
		line_start[3] = (n + n + 1) * square_y + n + square_x + square_size;
		// step is one line
		line_step[3] = n + n + 1;

		for (int i = 0; i < square_size; i++)
			for (int j = 0; j < 4; j++)
			{
				sticks.push_back(line_start[j] + line_step[j] * i);
			}

		return sticks;
	}
};

struct state
{
	// the shared puzzle
	static puzzle the_puzzle;

	ull stick_map = 0;
	ull square_map = 0;
	int remove_count = 0;

	state(int n)
	{
		// all sticks and squares are present initially.
		stick_map = ~(~((ull)0) << the_puzzle.total_sticks);
		square_map = ~(~((ull)0) << the_puzzle.total_squares);
	}

	// finished when all squares get covered by removed sticks.
	bool is_finished() const { return !(square_map & the_puzzle.square_mask); }

	// get the next possible states for removing the square identified by the least significant bit in the square map.
	vector<state> next_states() const
	{
		vector<state> next_states;

		// use the remove least significant bit hack to remove the least square from the map.
		ull square_remove_lsb = square_map & (square_map - 1);
		ull square_lsb = square_map ^ square_remove_lsb;

		for (int i = 0; i < the_puzzle.total_sticks; i++)
		{
			ull stick_bit = ((ull)1) << i;
			if ((stick_map & stick_bit) // stick exists
				&& (the_puzzle.stick_square_bitmap[i] & square_lsb)) // stick covers the current square
			{
				next_states.push_back(this->remove(i));
			}
		}

		return next_states;
	}

	state remove(int stick) const
	{
		// copy this
		state ans = *this;

		// remove the stick from the stickmap;
		ans.stick_map &= ~((ull)1 << stick);

		// remove the squares covered by this stick
		ans.square_map &= ~the_puzzle.stick_square_bitmap[stick];

		// add 1 to the remove count;
		ans.remove_count++;

		return ans;
	}
};

puzzle state::the_puzzle;

// the ending state of the bfs is when all squares get covered.
// each layer in the bfs at least covers 1 more square, and for each layer, there is at most n * 4 next states, because the largest square is covered by 4n edge sticks.
// so the bfs time complexity is O(total_squares * n * 4) = O(total_squares * n) = O(n^4)
// given total_squares = 1 + 4 + 9 + 16 + ... + n^2
int bfs(state s)
{
	queue<state> bfs_queue;
	bfs_queue.push(s);

	while (!bfs_queue.empty())
	{
		auto next_states = bfs_queue.front().next_states();
		bfs_queue.pop();

		for (const auto& state : next_states)
		{
			if (state.is_finished())
			{
				return state.remove_count;
			}

			bfs_queue.push(state);
		}
	}

	// error, cannot find the answer through bfs.
	return -1;
}

int main()
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, k;

		cin >> n >> k;

		state::the_puzzle.initialize(n);
		state s(n);

		for (int j = 0; j < k; j++)
		{
			int stick;
			cin >> stick;
			s = s.remove(stick - 1);
		}

		cout << bfs(s) - k << endl;
	}

	return 0;
}