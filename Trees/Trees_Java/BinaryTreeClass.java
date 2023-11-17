import java.util.*;
public class BinaryTreeClass {
    class Node {
        public int data;
        public Node left;
        public Node right;

        public Node(int data) {
            this.data = data;
            this.left = this.right = null;
        }
    }

    public Node root;
    public Scanner scanner = new Scanner(System.in);

    public BinaryTreeClass() {
        this.root = null;
    }

    public void createTree() {
        Node p, n;
        int data;
        Queue<Node> q = new LinkedList<>();
        System.out.println("Enter the value of root:");
        data = scanner.nextInt();
        root = new Node(data);
        q.add(root);

        while (!q.isEmpty()) {
            p = q.poll();
            System.out.println("Enter left child of " + p.data);
            data = scanner.nextInt();
            if (data != -1) {
                n = new Node(data);
                p.left = n;
                q.add(n);
            }
            
            System.out.println("Enter right child of " + p.data);
            data = scanner.nextInt();
            if (data != -1) {
                n = new Node(data);
                p.right = n;
                q.add(n);
            }
        }
    }
    
    void preorder(Node p) {
        if (p != null) {
            System.out.println(p.data);
            preorder(p.left);
            preorder(p.right);
        }
    }

    void inorder(Node p) {
        if (p != null) {
            inorder(p.left);
            System.out.println(p.data);
            inorder(p.right);
        }
    }

    void postorder(Node p) {
        if (p != null) {
            postorder(p.left);
            postorder(p.right);
            System.out.println(p.data);
        }
    }
}
