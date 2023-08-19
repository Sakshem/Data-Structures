import java.util.*;

public class Main {
  public static void main(String[] args) {
		BinarySearchTree binarySearchTree = new BinarySearchTree();
		binarySearchTree.insert(binarySearchTree.root, 10);
		binarySearchTree.insert(binarySearchTree.root, 5);
		binarySearchTree.insert(binarySearchTree.root, 20);
		binarySearchTree.insert(binarySearchTree.root, 15);
		binarySearchTree.insert(binarySearchTree.root, 16);
		binarySearchTree.insert(binarySearchTree.root, 17);
		binarySearchTree.insert(binarySearchTree.root, 8);
		binarySearchTree.insert(binarySearchTree.root, 6);
		binarySearchTree.insert(binarySearchTree.root, 30);

		System.out.println("Inorder Traversal");
		binarySearchTree.inOrder(binarySearchTree.root);

		System.out.println(binarySearchTree.delete(binarySearchTree.root, 10));

		System.out.println("Inorder Traversal");
		binarySearchTree.inOrder(binarySearchTree.root);
  }
}
