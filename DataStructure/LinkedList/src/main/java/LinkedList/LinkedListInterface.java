package LinkedList;

public interface LinkedListInterface {
    public void addFirst(Object data);
    public void addLast(Object data);
    public void add(int index, Object data);
    public String toString();
    public Object pop(int index);
    public int length();
    public Object get(int index);
    public int indexOf(Object data);
}
