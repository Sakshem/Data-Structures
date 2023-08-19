import java.util.HashMap;
import java.lang.Override;

public class Trie2 {
  private class Node {
    private char value;
    private HashMap<Character, Node> children;
    private boolean isEndOfWord;

    public Node(char value) {
      this.value = value;
      this.isEndOfWord = false;
      this.children = new HashMap<>();
    }

    public void addChildren(char ch) {
      children.put(ch, new Node(ch));
    }

    public boolean hasChild(char ch) {
      return children.containsKey(ch);
    }

    public Node getChild(char ch) {
      return children.get(ch);
    }

    public void setEndOfWord(boolean flag) {
      this.isEndOfWord = flag;
    }

    public boolean checkEndOfWord() {
      return isEndOfWord;
    }

    @Override
    public String toString() {
      return "value=" + value;
    }
  }

  private Node root;

  public Trie2() {
    this.root = new Node('\0');
  }

  public void insert(String word) {
    var current = root;
    for (var ch : word.toCharArray()) {
      if (!current.hasChild(ch)) {
        current.addChildren(ch);
      }
      current = current.getChild(ch);
    }
    current.setEndOfWord(true);
  }

  public boolean containsWord(String word) {
    if (word == null) {
      return false;
    }
    var current = root;
    for (var ch : word.toCharArray()) {
      if (current.hasChild(ch)) {
        current = current.getChild(ch);
      } else {
        return false;
      }
    }
    return current.checkEndOfWord();
  }
}
