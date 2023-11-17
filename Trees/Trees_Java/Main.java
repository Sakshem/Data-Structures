public class Main {
    public static void main(String[] args) {
        BinaryTreeClass bt = new BinaryTreeClass();
        bt.createTree();
        System.out.println();
        bt.preorder(bt.root);
        System.out.println();
        bt.postorder(bt.root);
        System.out.println();
        bt.inorder(bt.root);
    }
}
