#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Here we declare the mutex that will
// be used to prevent multiple threads
// accessing the same code.
mutex example_mutex;

// This global variable will be altered
// by multiple threads, we need to make
// sure they do it one at a time.
int i = 0;

// This is our thread unsafe method (i.e.
// multiple threads shouldn't execute the
// contents at the same time).
void doSomethingThreadUnsafe() {

  // We lock and unlock the mutex at the start
  // and finish of the method, making any threads
  // trying to access the enclosed code wait.
  example_mutex.lock();
  cout << "This is invocation number " << i++ << ", no other thread can get in!" << endl;
  example_mutex.unlock();
}

// This is our thread unsafe method (i.e.
// multiple threads shouldn't execute the
// contents at the same time).
void scopedLocksExample() {

  // We lock and unlock the mutex at the start
  // and finish of the method, making any threads
  // trying to access the enclosed code wait.
  scoped_lock lock(example_mutex);
  cout << "This is invocation number " << i++ << ", no other thread can get in!" << endl;
}

int main() {

  // Here we create three threads, all trying to do something
  // unsafe
  thread thread_one(doSomethingThreadUnsafe);
  thread thread_two(doSomethingThreadUnsafe);
  thread thread_three(doSomethingThreadUnsafe);

  // Here we make sure that the main thread waits for the other
  // three to finish before it exits.
  thread_one.join();
  thread_two.join();  
  thread_three.join();  

  return 0;
}