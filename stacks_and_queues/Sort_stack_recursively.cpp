#include <bits/stdc++.h>
using namespace std;

// Function to insert an element in the sorted stack
void sortedInsert(stack<int>& st, int element) {
    // Base case: If the stack is empty or the element is greater than the top
    if (st.empty() || element > st.top()) {
        st.push(element);
        return;
    }

    // Remove the top element and recurse
    int topElement = st.top();
    st.pop();
    sortedInsert(st, element);

    // Put the removed element back
    st.push(topElement);
}

// Function to sort the stack
void sortStack(stack<int>& st) {
    // Base case: If stack is empty or contains only one element
    if (st.empty() || st.size() == 1) {
        return;
    }

    // Remove the top element
    int topElement = st.top();
    st.pop();

    // Recursively sort the remaining stack
    sortStack(st);

    // Insert the removed element back in the sorted stack
    sortedInsert(st, topElement);
}

// Utility function to print the stack
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original Stack: ";
    printStack(st);

    // Re-initialize the stack as it gets emptied during print
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sortStack(st);

    cout << "Sorted Stack: ";
    printStack(st);

    return 0;
}
