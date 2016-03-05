
public class linkedList {
	Node head;
	Node current;
	
	public class Node {
		int data;
		Node next;
		
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
			current = current.next;
		}
	}
	
}