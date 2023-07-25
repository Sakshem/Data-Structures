import java.util.*;
class Node {
    public int data;
    public Node left;
    public Node right;
    public Node() {
	left = right = null;
    }
    public Node(int data) {
	this.data = data;
	left = right = null;
    }
}
public class BinarySearchTree {
    public Node root;
    public Scanner sc = new Scanner(System.in);
    public BinarySearchTree() {
	root = null;
    }
    public boolean find(Node p, int value) {
	if (p == null) return false;
	if (p.data == value) return true;

	if (p.data < value) {
	    return find(p.right, value);
	}

	return find(p.left, value);
    }

    public void insertRecursive(Node p, int value) {
	if (p == null) {
	    // meaning the tree is empty
	    Node n = new Node(value);
	    root = n;
	    return;
	}
	if (value > p.data) {
	    if (p.right == null) {
		Node n = new Node(value);
		p.right = n;
		return;
	    }
	    insertRecursive(p.right, value);
	}
	else if (value <= p.data) {
	    if (p.left == null) {
		Node n = new Node(value);
		p.left = n;
		return;
	    }
	    insertRecursive(p.left, value);
	}
    }
    public void insert(Node p, int value) {
	// here p is the same as root pointer
	if (root == null) {
	    Node n = new Node(value);
	    root = n;
	}
	else {
	    Node t = null;
	    while (p != null) {
		t = p;
		if (value <= p.data) {
		    p = p.left;
		}
		else if (value > p.data) {
		    p = p.right;
		}
	    }
	    p = new Node(value);
	    if (value < t.data) t.left = p;
	    else t.right = p;
	}
    }

    public Node delete(Node p, int key) {
	Node q;
	if (p == null) {
	    return null;
	}

	if (p.left == null && p.right == null) {
	    if (p == root) root = null;
	    p = null;
	    return null;
	}
	if (key < p.data) {
	    p.left = delete(p.left, key);
	}
	else if (key > p.data) {
	    p.right = delete(p.right, key);
	}
	else {
	    if (height(p.left) > height(p.right)) {
		q = inorderPredecessor(p.left);
		p.data = q.data;
		p.left = delete(p.left, q.data);
	    }
	    else {
		q = inorderSuccessor(p.right);
		p.data = q.data;
		p.right = delete(p.right, q.data);
	    }
	}
	return p;
    }

    public Node inorderSuccessor(Node p) {
	while (p != null && p.left != null) {
	    p = p.left;
	}
	return p;
    }

    public Node inorderPredecessor(Node p) {
	while (p != null && p.right != null) {
	    p = p.right;
	}
	return p;
    }

    public void levelOrder() {
	Node p = null;
	Queue<Node> q = new LinkedList<>();
	if (root != null) {
	    q.add(root);
	    System.out.print(root.data + " ");
	}
	while (!q.isEmpty()) {
	    p = q.poll();
	    if (p.left != null) {
		q.add(p.left);
		System.out.print(p.left.data + " ");
	    }
	    if (p.right != null) {
		q.add(p.right);
		System.out.print(p.right.data + " ");
	    }
	}
    }

    public void preOrder(Node p) {
	if (p != null) {
	    System.out.print(p.data + " ");
	    preOrder(p.left);
	    preOrder(p.right);
	}
    }

    public void inOrder(Node p) {
	if (p != null) {
	    inOrder(p.left);
	    System.out.print(p.data + " ");
	    inOrder(p.right);
	}
    }

    public void postOrder(Node p) {
	if (p != null) {
	    postOrder(p.left);
	    postOrder(p.right);
	    System.out.print(p.data + " ");
	}
    }

    public int height(Node root) {
	if (root == null) {
	    return 0;
	}
	return 1 + Math.max(height(root.left), height(root.right));
    }

    public int count(Node root) {
	if (root == null) {
	    return 0;
	}
	return 1 + count(root.left) + count(root.right);
    }
}
