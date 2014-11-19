import java.util.*;

public class LinkedList
{
    Node head;
    Node tail;
    int size;

    public LinkedList()
    {
	this.size = 0;
    }

    public LinkedList(int data)
    {
	Node node = new Node(data);
	this.size++;
	this.head = node;
	this.tail = node;
	
    }

    public void addLast(int data)
    {
	Node node = new Node(data);
	this.size++;
	if (isEmpty()) {
	    this.head = node;
	    this.tail = node;
	    return;
	}
	this.tail.next = node;
	this.tail = node;
    }

    public void addFirst(int data)
    {
	Node node = new Node(data);
	this.size++;
	if (isEmpty()) {
	    this.head = node;
	    this.tail = node;
	    return;
	}
	this.node.next = head;
	this.head = node;
    }

    public boolean isEmpty()
    {
	return this.size == 0;
    }

    public void delete(int value)
    {
	Node prevNode = null;
	Node targetNode = this.head;

	if (isEmpty()) {
	    return;
	}
	
	if (this.head.data == value) {
	    this.head = this.head.next;
	    targetNode.next = null;
	    size--;
	    return;
	}
	
	prevNode = this.head;
	while (prevNode.next != null && prevNode.next.data != value) {
	    prevNode = prevNode.next;
	    targetNode = prevNode.next;
	}   

	if (targetNode.next != this.tail) {
	    prevNode.next = targetNode.next;
	    targetNode.next = null;
	    size--;
	    return;
	} else if (targetNode == this.tail && targetNode.data == value) {
	    prevNode.next = null;
	    this.tail = prevNode;
	    size--;
	    return;
	}
	
}
