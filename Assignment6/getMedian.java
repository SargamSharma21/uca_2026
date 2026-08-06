import java.util.Collections;
import java.util.PriorityQueue;

class RunningMedian {

    private PriorityQueue<Integer> left;

    private PriorityQueue<Integer> right;

    public RunningMedian() {
        left = new PriorityQueue<>(Collections.reverseOrder());
        right = new PriorityQueue<>();
    }

    // Insert a number into the data structure
    public void insert(int num) {

        if (left.isEmpty() || num <= left.peek()) {
            left.offer(num);
        } else {
            right.offer(num);
        }

        // Balance the heaps
        if (left.size() > right.size() + 1) {
            right.offer(left.poll());
        } else if (right.size() > left.size()) {
            left.offer(right.poll());
        }
    }

    public float getMedian() {

        if (left.size() == right.size()) {
            return (left.peek() + right.peek()) / 2.0f;
        }

        return left.peek();
    }

    public static void main(String[] args) {

        RunningMedian rm = new RunningMedian();

        int[] stream = {5, 15, 1, 3};

        for (int num : stream) {
            rm.insert(num);
            System.out.println("Inserted: " + num +
                               "  Median: " + rm.getMedian());
        }
    }
}