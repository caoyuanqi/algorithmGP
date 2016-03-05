
public class linkedList {
	Node head;
	Node current;
	
	public class Node {
		int data;
		Node next;
		Node previous;
		
		public Node(int data) {
			this.data = data;
		}
	}
	
	public void add(int data) {
		if(head == null) {
			head = new Node(data);
			current = head;
		}
		else {
			current.next = new Node(data);
			current.next.previous = current; 
			current = current.next;
		}
	}
	
}
