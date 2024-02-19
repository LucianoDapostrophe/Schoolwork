

#include <iostream>
#include <queue>
#include <set>

struct State {
	int nearC = 0;
	int nearM = 0;
	int boat = 0;
	int farC = 0;
	int farM = 0;
	bool operator==(const State& other) const {
		return nearC == other.nearC && nearM == other.nearM &&
			boat == other.boat &&
			farC == other.farC && farM == other.farM;
	}
	bool operator<(const State& rhs) const {
		return farC < rhs.farC;
	}
};

bool Is_Valid(State state, std::set<State>* repeats) {
	if (state.nearM >= state.nearC && state.farM >= state.farC && repeats->find(state) == repeats->end()) {
		return true;
	}
	return false;
}

void Successor_Function(State state, std::queue<State>* queue, std::set<State>* repeats) {
	if (state.boat == 0) {
		if (state.nearM >= 2) {
			State twoMState = state;
			twoMState.nearM -= 2;
			twoMState.farM += 2;
			twoMState.boat = 1;
			if (Is_Valid(twoMState, repeats)) {
				queue->push(twoMState);
				repeats->insert(twoMState);
			}
		}
		if (state.nearC >= 2) {
			State twoCState = state;
			twoCState.nearC -= 2;
			twoCState.farC += 2;
			twoCState.boat = 1;
			if (Is_Valid(twoCState, repeats)) {
				queue->push(twoCState);
				repeats->insert(twoCState);
			}
		}
		if (state.nearM > 0) {

			State addState = state;
			addState.nearM--;
			addState.farM++;
			addState.boat = 1;
			if (Is_Valid(addState, repeats)) {
				queue->push(addState);
				repeats->insert(addState);
			}
			if (state.nearC > 0) {
				addState.nearC--;
				addState.farC++;
				if (Is_Valid(addState, repeats)) {
					queue->push(addState);
					repeats->insert(addState);
				}
			}
		}
		if (state.nearC > 0) {
			State addState = state;
			addState.nearC--;
			addState.farC++;
			addState.boat = 1;
			if (Is_Valid(addState, repeats)) {
				queue->push(addState);
				repeats->insert(addState);
			}
		}
		
	}
	else {
		if (state.farM >= 2) {
			State twoMState = state;
			twoMState.farM -= 2;
			twoMState.nearM += 2;
			twoMState.boat = 0;
			if (Is_Valid(twoMState, repeats)) {
				queue->push(twoMState);
				repeats->insert(twoMState);
			}
		}
		if (state.farC >= 2) {
			State twoCState = state;
			twoCState.farC -= 2;
			twoCState.nearC += 2;
			twoCState.boat = 0;
			if (Is_Valid(twoCState, repeats)) {
				queue->push(twoCState);
				repeats->insert(twoCState);
			}
		}
		if (state.farM > 0) {
			State addState = state;
			addState.farM--;
			addState.nearM++;
			addState.boat = 0;
			if (Is_Valid(addState, repeats)) {
				queue->push(addState);
				repeats->insert(addState);
			}
			if (state.farC > 0) {
				addState.farC--;
				addState.nearC++;
				if (Is_Valid(addState, repeats)) {
					queue->push(addState);
					repeats->insert(addState);
				}
			}
		}
		if (state.farC > 0) {
			State addState = state;
			addState.farC--;
			addState.nearC++;
			if (Is_Valid(addState, repeats)) {
				queue->push(addState);
				repeats->insert(addState);
			}
		}
	}
}

bool Solved(State current) {
	if (current.farC != 3 && current.farM != 3 && current.boat != 1) {
		return false;
	}
	return true;
}

int main()
{
	State start;
	start.nearC = 3;
	start.nearM = 3;
	std::queue<State>* myQueue = new std::queue<State>();
	std::set<State>* repeats = new std::set<State>();
	myQueue->push(start);
	while (!Solved(myQueue->front())) {
		State node = myQueue->front();
		myQueue->pop();
		Successor_Function(node, myQueue, repeats);
	}
	std::cout << "solved" << std::endl;
}
