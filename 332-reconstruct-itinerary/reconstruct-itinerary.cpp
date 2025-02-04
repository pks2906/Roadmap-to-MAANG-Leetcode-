class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the graph
        unordered_map<string, map<string, int>> graph;
        for (const auto& ticket : tickets) {
            graph[ticket[0]][ticket[1]]++;
        }

        vector<string> itinerary;
        dfs("JFK", graph, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

private:
    void dfs(const string& airport,
             unordered_map<string, map<string, int>>& graph,
             vector<string>& itinerary) {
        auto& destinations = graph[airport];
        while (!destinations.empty()) {
            auto next = destinations.begin()->first;
            if (--destinations[next] == 0) {
                destinations.erase(next);
            }
            dfs(next, graph, itinerary);
        }
        itinerary.push_back(airport);
    }
};