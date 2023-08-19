public class Main {
  public static void main(String[] args) {
    var graph = new Graph();
    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addEdge("A", "B");
    graph.addEdge("B", "C");
    graph.addEdge("C", "A");
    System.out.println(graph.hasCycle());
    // graph.addNode("A");
    // graph.addNode("B");
    // graph.addNode("C");
    // graph.addNode("D");
    //
    // graph.addEdge("A", "B");
    // graph.addEdge("B", "D");
    // // graph.removeEdge("A", "C");
    // // graph.removeNode("A");
    // graph.addEdge("D", "C");
    // graph.addEdge("A", "C");
    // graph.print();
    // System.out.println("DFS: ");
    // graph.traverseDepthFirst("A");
    //
    // System.out.println("BFS: ");
    // graph.traverseBreadthFirst("A");
    //
    // System.out.println("Topological sort:");
    // var list = graph.topologicalSort();
    // System.out.println(list);
  }
}
