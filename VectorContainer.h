#ifndef VECTORCONTAINER_H
#define VECTORCONTAINER_H

#include <iostream>
#include <vector>
#include <iterator>

#include "container.h"
#include "strategy.h"

using namespace std;

class VectorContainer: public Container {
	private:
		vector<Base*> vec;

	public:
		void add_element(Base* element) {
			vec.push_back(element);
		};
		
		void print() {
			vector<Base*>::const_iterator it;
			for(it = vec.begin();it != vec.end(); ++it) {
				cout << (*it)->evaluate() << " ";
			}
		};
		
		void sort() {
			try {
				if(sort_function == NULL) {
					throw 1;
				}
				sort_function->sort(this);
			}
			catch(int error_val) {
				cout << "Error: Sort function not selected." << endl;
			}

		};

		void swap(int i, int j) {
			Base* temp = vec.at(i);
			vec.at(i) = vec.at(j);
			vec.at(j) = temp;
		};

		Base* at(int i) {
			return vec.at(i);
		};

		int size() {
			return vec.size();
		};
};

#endif
