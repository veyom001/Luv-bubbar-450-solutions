// we define maxsize that the stack may take. also an array which store stack's data and a top that keeps the pointer to the top element of the stock.

public class MyStack {
   private int maxSize;
   private long[] stackArray;
   private int top;
   
  // making mystack custom constructor
   public MyStack(int s) {
      maxSize = s;
      stackArray = new long[maxSize];
      top = -1;
   }
  // note: we used ++top so that first we increment top from -1 to 0 and push our element and keeps the top to 1 now.
   public void push(long j) {
      stackArray[++top] = j;
   }
   public long pop() {
      return stackArray[top--];
   }
  // peek returns the top of our stack
  
   public long peek() {
      return stackArray[top];
   }
   public boolean isEmpty() {
      return (top == -1);
   }
   public boolean isFull() {
      return (top == maxSize - 1);
   }
