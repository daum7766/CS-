package LinkedList;

import java.lang.Object;

public class Node {
    private Object data;
    private Node next;

    // 생성자는 반환값이 없다.
    public Node(Object data) {
        this.data = data;
        this.next = null;
    }

    public Object get_data() {
        return this.data;
    }

    public Node get_next() {
        return this.next;
    }

    public void set_data(Object data) {
        this.data = data;
    }

    public void set_next(Node next) {
        this.next = next;
    }
}
