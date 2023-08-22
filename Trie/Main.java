public class Main {

  public static void main(String[] args) {
    Trie2 trie = new Trie2();
    // trie.insert("cat");
    // trie.insert("dog");
    // trie.insert("can");
    trie.insert("car");
    trie.insert("care");
    trie.remove("carex");
    // System.out.println(trie.containsWord("ca"));
    // trie.preorderTraverse();
    // trie.postorderTraverse();
    System.out.println(trie.containsWord("car"));
  }

}
