public class Main {

  public static void main(String[] args) {
    Trie2 trie = new Trie2();
    trie.insert("cat");
    trie.insert("dog");
    trie.insert("can");
    System.out.println(trie.containsWord("ca"));
  }

}
