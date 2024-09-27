
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Here I define a structure for the edges
struct Edge {
    int to, wt;
};

// This is the Heap class (min-heap) to store vertices and their minimum edge costs
class MinHeap {
public:
    MinHeap(int size) : size(0) {
        heap.resize(size);
        position.resize(size);
        key.resize(size, INT_MAX);
    }

    void insert(int vertex, int edge_cost) {
        heap[size] = vertex;
        position[vertex] = size;
        key[vertex] = edge_cost;
        size++;
        heapify_up(size - 1);
    }

    // to decrease the key (edge cost) of a vertex
    void decrease_key(int vertex, int new_edge_cost) {
        int ind = position[vertex];
        key[vertex] = new_edge_cost;
        heapify_up(ind);
    }

    // here I extract the vertex with the minimum edge cost
    int extract_min() {
        if (size == 0) return -1;
        int rt = heap[0];
        heap[0] = heap[size - 1];
        position[heap[0]] = 0;
        size--;
        heapify_down(0);
        return rt;
    }

    bool is_empty() {
        return size == 0;
    }

    int get_key(int vertex) {
        return key[vertex];
    }

private:
    vector<int> heap;
    vector<int> position;
    vector<int> key;
    int size;

    void heapify_up(int ind) {
        while (ind > 0 && key[heap[ind]] < key[heap[prnt(ind)]]) {
            swap(heap[ind], heap[prnt(ind)]);
            position[heap[ind]] = ind;
            position[heap[prnt(ind)]] = prnt(ind);
            ind = prnt(ind);
        }
    }

    void heapify_down(int ind) {
        int minute = ind;
        int lc = left(ind);
        int rc = right(ind);

        if (lc < size && key[heap[lc]] < key[heap[minute]]) {
            minute = lc;
        }
        if (rc < size && key[heap[rc]] < key[heap[minute]]) {
            minute = rc;
        }

        if (minute != ind) {
            swap(heap[ind], heap[minute]);
            position[heap[ind]] = ind;
            position[heap[minute]] = minute;
            heapify_down(minute);
        }
    }

    int prnt(int ind) { return (ind - 1) / 2; }
    int left(int ind) { return 2 * ind + 1; }
    int right(int ind) { return 2 * ind + 2; }
};

// Here's the function to perform Prim's MST algorithm
int prim_mst(int num_ver, const vector<vector<Edge> >& graph) {
    MinHeap heap(num_ver);
    vector<bool> in_mst(num_ver, false);  
    vector<int> key(num_ver, INT_MAX);    // To store minimum edge wt for each vertex
    int total_wt = 0;                    

    // Start with vertex 0
    key[0] = 0;
    heap.insert(0, 0);

    while (!heap.is_empty()) {
        // we have to extract vertex with the minute edge cost
        int u = heap.extract_min();

        if (in_mst[u]) continue;
        in_mst[u] = true;
        total_wt += key[u];

        //to  eexplore all adjacent vertices
        for (size_t i = 0; i < graph[u].size(); ++i) {
            const Edge& edge = graph[u][i];
            int v = edge.to;
            int wt = edge.wt;

            if (!in_mst[v] && wt < key[v]) {
                key[v] = wt;
                if (heap.get_key(v) == INT_MAX) {
                    heap.insert(v, key[v]);
                } else {
                    heap.decrease_key(v, key[v]);
                }
            }
        }
    }

    return total_wt;
}

int main() {
    int num_ver, num_edg;
    cin >> num_ver >> num_edg;

    // This is where I Created an adjacency list for the graph
    vector<vector<Edge> > graph(num_ver);

    for (int i = 0; i < num_edg; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        Edge e1;
        e1.to = v;
        e1.wt = wt;
        graph[u].push_back(e1);

        // Since MST operates on undirected graphs, add the reverse edge as well
        Edge e2;
        e2.to = u;
        e2.wt = wt;
        graph[v].push_back(e2);
    }

    // Run Prim's algorithm
    int result = prim_mst(num_ver, graph);

    // Print the total wt of the MST
    cout << "The total wt of the MST is : "<<result << endl;

    return 0;
}



