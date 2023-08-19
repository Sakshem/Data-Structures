import java.lang.Override;

public class Trie {
  public static int ALPHABET_SIZE = 26;

  private class Node {
    private char value;
    private Node[] children;
    private boolean isEndOfWord;

    public Node(char value) {
      this.value = value;
      this.children = new Node[ALPHABET_SIZE];
      this.isEndOfWord = false;
    }

    @Override
    public String toString() {
      return "value = " + value;
    }
  }

  private Node root;

  public Trie() {
    root = new Node('\0');
  }

  public void insert(String word) {
    var current = root;
    for (var ch : word.toCharArray()) {
      // handles lowercase letters right now
      var index = ch - 'a';
      if (current.children[index] == null) {
        current.children[index] = new Node(ch);
      }
      current = current.children[index];
    }
    current.isEndOfWord = true;
  }
}
