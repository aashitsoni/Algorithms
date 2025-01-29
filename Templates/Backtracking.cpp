void dfs(int startIndex, std::vector<T> path, std::vector<std::vector<T>>& res, [...additional states]) {
    if (isLeaf(path)) {
        // add a copy of the path to the result
        res.emplace_back(std::vector<T>(path));
        return;
    }
    for (auto edge : getEdges(startIndex, [...additional states])) {
        path.emplace_back(choice);
        if (...additional states) update(...additional states)
        dfs(startIndex + edge.length(), path, res, [...addtional states]);
        path.pop();
        // revert(...additional states) if necessary, e.g. permutations
    }
}
