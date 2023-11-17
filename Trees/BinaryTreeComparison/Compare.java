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
class BinaryTree {
    public Node root;
    public Scanner sc = new Scanner(System.in);
    public BinaryTree() {
		root = null;
    }

    public void createTree() {
		int x;
		System.out.println("Enter value of the root: " );
		x = sc.nextInt();
		root = new Node(x);
		Node p, n;
		Queue<Node> q = new LinkedList<>();
		q.add(root);
		while (!q.isEmpty()) {
	    	p = q.poll();
	    	System.out.println("Enter value of the left child of " + p.data);
	    	x = sc.nextInt();
	    if (x != -1) {
				n = new Node(x);
				p.left = n;
				q.add(n);
	    	}

	    	System.out.println("Enter value of the right child of " + p.data);
	    	x = sc.nextInt();
	    if (x != -1) {
				n = new Node(x);
				p.right = n;
				q.add(n);
	    	}
		}
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
public class compare {

    public static boolean compare(Node a, Node b) {
		if (a == null && b == null) return true;

		if (a == null || b == null) return false;

		if (a.data != b.data) return false;

		return compare(a.left, b.left) && compare(a.right, b.right);
    }

    public static void main(String[] args) {
		BinaryTree binaryTree1 = new BinaryTree();
		BinaryTree binaryTree2 = new BinaryTree();

		System.out.println("Create first binarytree");
		binaryTree1.createTree();


		System.out.println("Create second binarytree" );
		binaryTree2.createTree();

		boolean result = compare(binaryTree1.root, binaryTree2.root);
	
		if (result == true) {
	    	System.out.println("Both the binary trees are identical");
		}
		else {
	    	System.out.println("Both the binary trees are NOT identical");
		}
    }
}
