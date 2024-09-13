---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/ProjectSelectionProblem.hpp\"\n\n#include <cassert>\n\
    #include <limits>\n#include <vector>\n\n#include <atcoder/maxflow>\n\ntemplate\
    \ <class Cap> struct ProjectSelectionProblem {\n    struct Edge {\n        int\
    \ from, to;\n        Cap cost;\n\n        Edge(int from, int to, Cap cost) : from(from),\
    \ to(to), cost(cost) {\n        }\n    };\n    int n, mf_n, s, t;\n    Cap base;\n\
    \    std::vector<Edge> edges;\n    atcoder::mf_graph<Cap> g;\n\n    ProjectSelectionProblem()\
    \ {\n    }\n    ProjectSelectionProblem(int n_)\n        : n(n_), mf_n(n_ + 2),\
    \ s(n_), t(n_ + 1), base(0) {\n    }\n\n    /**\n     * \u9802\u70B9 u \u304C\u8D64\
    \u8272\u304B\u3064\u9802\u70B9 v \u304C\u9752\u8272\u3060\u3068\u30DA\u30CA\u30EB\
    \u30C6\u30A3\u3092\u53D7\u3051\u308B\n     */\n    void if_u_red_and_v_blue_then_penalty(int\
    \ u, int v, Cap penalty) {\n        assert(0 <= u && u < n && 0 <= v && v < n\
    \ && u != v && penalty >= 0);\n        edges.emplace_back(u, v, penalty);\n  \
    \  }\n\n    /**\n     * \u9802\u70B9 v \u304C\u8D64\u8272\u306B\u306A\u308B\u3068\
    \u30DA\u30CA\u30EB\u30C6\u30A3\u3092\u53D7\u3051\u308B\n     */\n    void red_penalty(int\
    \ v, Cap penalty) {\n        assert(0 <= v && v < n && penalty >= 0);\n      \
    \  edges.emplace_back(v, t, penalty);\n    }\n\n    /**\n     * \u9802\u70B9 v\
    \ \u304C\u9752\u8272\u306B\u306A\u308B\u3068\u30DA\u30CA\u30EB\u30C6\u30A3\u3092\
    \u53D7\u3051\u308B\n     */\n    void blue_penalty(int v, Cap penalty) {\n   \
    \     assert(0 <= v && v < n && penalty >= 0);\n        edges.emplace_back(s,\
    \ v, penalty);\n    }\n\n    /**\n     * \u9802\u70B9 u \u3068 v \u306E\u8272\u304C\
    \u7570\u306A\u308B\u3068\u30DA\u30CA\u30EB\u30C6\u30A3\u3092\u53D7\u3051\u308B\
    \n     */\n    void difference_penalty(int u, int v, Cap penalty) {\n        assert(0\
    \ <= u && u < n && 0 <= v && v < n && u != v && penalty >= 0);\n        edges.emplace_back(u,\
    \ v, penalty);\n        edges.emplace_back(v, u, penalty);\n    }\n\n    /**\n\
    \     * \u9802\u70B9 u \u304C\u8D64\u8272\u306B\u306A\u308B\u3068\u9802\u70B9\
    \ v \u3082\u8D64\u8272\u306B\u306A\u308B\n     */\n    void if_u_red_then_v_red(int\
    \ u, int v) {\n        assert(0 <= u && u < n && 0 <= v && v < n && u != v);\n\
    \        edges.emplace_back(u, v, std::numeric_limits<Cap>::max());\n    }\n\n\
    \    /**\n     * \u9802\u70B9 u \u304C\u9752\u8272\u306B\u306A\u308B\u3068\u9802\
    \u70B9 v \u3082\u9752\u8272\u306B\u306A\u308B\n     */\n    void if_u_blue_then_v_blue(int\
    \ u, int v) {\n        assert(0 <= u && u < n && 0 <= v && v < n && u != v);\n\
    \        edges.emplace_back(v, u, std::numeric_limits<Cap>::max());\n    }\n\n\
    \    /**\n     * \u9802\u70B9 v \u304C\u8D64\u8272\u306B\u306A\u308B\n     */\n\
    \    void force_red(int v) {\n        assert(0 <= v && v < n);\n        edges.emplace_back(s,\
    \ v, std::numeric_limits<Cap>::max());\n    }\n\n    /**\n     * \u9802\u70B9\
    \ v \u304C\u9752\u8272\u306B\u306A\u308B\n     */\n    void force_blue(int v)\
    \ {\n        assert(0 <= v && v < n);\n        edges.emplace_back(v, t, std::numeric_limits<Cap>::max());\n\
    \    }\n\n    /**\n     * \u9802\u70B9 u \u3068 v \u304C\u540C\u3058\u8272\u306B\
    \u306A\u308B\n     */\n    void force_same(int u, int v) {\n        assert(0 <=\
    \ u && u < n && 0 <= v && v < n && u != v);\n        edges.emplace_back(u, v,\
    \ std::numeric_limits<Cap>::max());\n        edges.emplace_back(v, u, std::numeric_limits<Cap>::max());\n\
    \    }\n\n    /**\n     * \u9802\u70B9 v \u304C\u8D64\u8272\u306B\u306A\u308B\u3068\
    \u5831\u916C\u3092\u5F97\u308B\n     */\n    void red_reward(int v, Cap reward)\
    \ {\n        assert(0 <= v && v < n && reward >= 0);\n        base += reward;\n\
    \        edges.emplace_back(s, v, reward);\n    }\n\n    /**\n     * \u9802\u70B9\
    \ v \u304C\u9752\u8272\u306B\u306A\u308B\u3068\u5831\u916C\u3092\u5F97\u308B\n\
    \     */\n    void blue_reward(int v, Cap reward) {\n        assert(0 <= v &&\
    \ v < n && reward >= 0);\n        base += reward;\n        edges.emplace_back(v,\
    \ t, reward);\n    }\n\n    /**\n     * \u9802\u70B9 u \u3068 v \u304C\u540C\u3058\
    \u8272\u306B\u306A\u308B\u3068\u5831\u916C\u3092\u5F97\u308B\n     */\n    void\
    \ same_reward(int u, int v, Cap reward) {\n        assert(0 <= u && u < n && 0\
    \ <= v && v < n && u != v && reward >= 0);\n        base += reward;\n        edges.emplace_back(u,\
    \ v, reward);\n        edges.emplace_back(v, u, reward);\n    }\n\n    /**\n \
    \    * \u8D64\u8272\u306E\u9802\u70B9\u304C\u5B58\u5728\u3059\u308B\u3068\u30DA\
    \u30CA\u30EB\u30C6\u30A3\u3092\u53D7\u3051\u308B\n     */\n    void any_red_peanlty(int\
    \ u, int v, Cap penalty) {\n        assert(0 <= u && u < n && 0 <= v && v < n\
    \ && u != v && penalty >= 0);\n        edges.emplace_back(v, t, penalty);\n  \
    \      edges.emplace_back(u, v, penalty);\n    }\n\n    /**\n     * \u8D64\u8272\
    \u306E\u9802\u70B9\u304C\u5B58\u5728\u3059\u308B\u3068\u30DA\u30CA\u30EB\u30C6\
    \u30A3\u3092\u53D7\u3051\u308B\n     */\n    void any_red_peanlty(const std::vector<int>&\
    \ vs, Cap penalty) {\n        int u = mf_n++;\n        for (int v : vs) {\n  \
    \          assert(0 <= v && v < n);\n            edges.emplace_back(v, u, std::numeric_limits<Cap>::max());\n\
    \        }\n        edges.emplace_back(u, t, penalty);\n    }\n\n    /**\n   \
    \  * \u9752\u8272\u306E\u9802\u70B9\u304C\u5B58\u5728\u3059\u308B\u3068\u30DA\u30CA\
    \u30EB\u30C6\u30A3\u3092\u53D7\u3051\u308B\n     */\n    void any_blue_penalty(int\
    \ u, int v, Cap penalty) {\n        assert(0 <= u && u < n && 0 <= v && v < n\
    \ && u != v && penalty >= 0);\n        edges.emplace_back(s, u, penalty);\n  \
    \      edges.emplace_back(u, v, penalty);\n    }\n\n    /**\n     * \u9752\u8272\
    \u306E\u9802\u70B9\u304C\u5B58\u5728\u3059\u308B\u3068\u30DA\u30CA\u30EB\u30C6\
    \u30A3\u3092\u53D7\u3051\u308B\n     */\n    void any_blue_penalty(const std::vector<int>&\
    \ vs, Cap penalty) {\n        int u = mf_n++;\n        for (int v : vs) {\n  \
    \          assert(0 <= v && v < n);\n            edges.emplace_back(u, v, std::numeric_limits<Cap>::max());\n\
    \        }\n        edges.emplace_back(s, u, penalty);\n    }\n\n    /**\n   \
    \  * \u9802\u70B9 u \u3068 v \u304C\u8D64\u8272\u306B\u306A\u308B\u3068\u5831\u916C\
    \u3092\u5F97\u308B\n     */\n    void all_red_reward(int u, int v, Cap reward)\
    \ {\n        assert(0 <= u && u < n && 0 <= v && v < n && u != v && reward >=\
    \ 0);\n        base += reward;\n        edges.emplace_back(s, u, reward);\n  \
    \      edges.emplace_back(u, v, reward);\n    }\n\n    /**\n     * \u3059\u3079\
    \u3066\u306E\u9802\u70B9\u304C\u8D64\u306B\u306A\u308B\u3068\u5831\u916C\u3092\
    \u5F97\u308B\n     */\n    void all_red_reward(const std::vector<int>& vs, Cap\
    \ reward) {\n        base += reward;\n        int u = mf_n++;\n        for (int\
    \ v : vs) {\n            assert(0 <= v && v < n);\n            edges.emplace_back(u,\
    \ v, std::numeric_limits<Cap>::max());\n        }\n        edges.emplace_back(s,\
    \ u, reward);\n    }\n\n    /**\n     * \u9802\u70B9 u \u3068 v \u304C\u9752\u8272\
    \u306B\u306A\u308B\u3068\u5831\u916C\u3092\u5F97\u308B\n     */\n    void all_blue_reward(int\
    \ u, int v, Cap reward) {\n        assert(0 <= u && u < n && 0 <= v && v < n &&\
    \ u != v && reward >= 0);\n        base += reward;\n        edges.emplace_back(v,\
    \ t, reward);\n        edges.emplace_back(u, v, reward);\n    }\n\n    /**\n \
    \    * \u3059\u3079\u3066\u306E\u9802\u70B9\u304C\u9752\u306B\u306A\u308B\u3068\
    \u5831\u916C\u3092\u5F97\u308B\n     */\n    void all_blue_reward(const std::vector<int>&\
    \ vs, Cap reward) {\n        base += reward;\n        int u = mf_n++;\n      \
    \  for (int v : vs) {\n            assert(0 <= v && v < n);\n            edges.emplace_back(v,\
    \ u, std::numeric_limits<Cap>::max());\n        }\n        edges.emplace_back(u,\
    \ t, reward);\n    }\n\n    /**\n     * \u5831\u916C\u306E\u6700\u5927\u5024\u3092\
    \u6C42\u3081\u308B\n     */\n    Cap solve() {\n        g = atcoder::mf_graph<Cap>(mf_n);\n\
    \        for (const auto& [u, v, cost] : edges) {\n            g.add_edge(u, v,\
    \ cost);\n        }\n        return base - g.flow(s, t);\n    }\n\n    std::vector<bool>\
    \ red_selection() {\n        auto selection = g.min_cut(s);\n        selection.resize(n);\n\
    \        return selection;\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \n#include <atcoder/maxflow>\n\ntemplate <class Cap> struct ProjectSelectionProblem\
    \ {\n    struct Edge {\n        int from, to;\n        Cap cost;\n\n        Edge(int\
    \ from, int to, Cap cost) : from(from), to(to), cost(cost) {\n        }\n    };\n\
    \    int n, mf_n, s, t;\n    Cap base;\n    std::vector<Edge> edges;\n    atcoder::mf_graph<Cap>\
    \ g;\n\n    ProjectSelectionProblem() {\n    }\n    ProjectSelectionProblem(int\
    \ n_)\n        : n(n_), mf_n(n_ + 2), s(n_), t(n_ + 1), base(0) {\n    }\n\n \
    \   /**\n     * \u9802\u70B9 u \u304C\u8D64\u8272\u304B\u3064\u9802\u70B9 v \u304C\
    \u9752\u8272\u3060\u3068\u30DA\u30CA\u30EB\u30C6\u30A3\u3092\u53D7\u3051\u308B\
    \n     */\n    void if_u_red_and_v_blue_then_penalty(int u, int v, Cap penalty)\
    \ {\n        assert(0 <= u && u < n && 0 <= v && v < n && u != v && penalty >=\
    \ 0);\n        edges.emplace_back(u, v, penalty);\n    }\n\n    /**\n     * \u9802\
    \u70B9 v \u304C\u8D64\u8272\u306B\u306A\u308B\u3068\u30DA\u30CA\u30EB\u30C6\u30A3\
    \u3092\u53D7\u3051\u308B\n     */\n    void red_penalty(int v, Cap penalty) {\n\
    \        assert(0 <= v && v < n && penalty >= 0);\n        edges.emplace_back(v,\
    \ t, penalty);\n    }\n\n    /**\n     * \u9802\u70B9 v \u304C\u9752\u8272\u306B\
    \u306A\u308B\u3068\u30DA\u30CA\u30EB\u30C6\u30A3\u3092\u53D7\u3051\u308B\n   \
    \  */\n    void blue_penalty(int v, Cap penalty) {\n        assert(0 <= v && v\
    \ < n && penalty >= 0);\n        edges.emplace_back(s, v, penalty);\n    }\n\n\
    \    /**\n     * \u9802\u70B9 u \u3068 v \u306E\u8272\u304C\u7570\u306A\u308B\u3068\
    \u30DA\u30CA\u30EB\u30C6\u30A3\u3092\u53D7\u3051\u308B\n     */\n    void difference_penalty(int\
    \ u, int v, Cap penalty) {\n        assert(0 <= u && u < n && 0 <= v && v < n\
    \ && u != v && penalty >= 0);\n        edges.emplace_back(u, v, penalty);\n  \
    \      edges.emplace_back(v, u, penalty);\n    }\n\n    /**\n     * \u9802\u70B9\
    \ u \u304C\u8D64\u8272\u306B\u306A\u308B\u3068\u9802\u70B9 v \u3082\u8D64\u8272\
    \u306B\u306A\u308B\n     */\n    void if_u_red_then_v_red(int u, int v) {\n  \
    \      assert(0 <= u && u < n && 0 <= v && v < n && u != v);\n        edges.emplace_back(u,\
    \ v, std::numeric_limits<Cap>::max());\n    }\n\n    /**\n     * \u9802\u70B9\
    \ u \u304C\u9752\u8272\u306B\u306A\u308B\u3068\u9802\u70B9 v \u3082\u9752\u8272\
    \u306B\u306A\u308B\n     */\n    void if_u_blue_then_v_blue(int u, int v) {\n\
    \        assert(0 <= u && u < n && 0 <= v && v < n && u != v);\n        edges.emplace_back(v,\
    \ u, std::numeric_limits<Cap>::max());\n    }\n\n    /**\n     * \u9802\u70B9\
    \ v \u304C\u8D64\u8272\u306B\u306A\u308B\n     */\n    void force_red(int v) {\n\
    \        assert(0 <= v && v < n);\n        edges.emplace_back(s, v, std::numeric_limits<Cap>::max());\n\
    \    }\n\n    /**\n     * \u9802\u70B9 v \u304C\u9752\u8272\u306B\u306A\u308B\n\
    \     */\n    void force_blue(int v) {\n        assert(0 <= v && v < n);\n   \
    \     edges.emplace_back(v, t, std::numeric_limits<Cap>::max());\n    }\n\n  \
    \  /**\n     * \u9802\u70B9 u \u3068 v \u304C\u540C\u3058\u8272\u306B\u306A\u308B\
    \n     */\n    void force_same(int u, int v) {\n        assert(0 <= u && u < n\
    \ && 0 <= v && v < n && u != v);\n        edges.emplace_back(u, v, std::numeric_limits<Cap>::max());\n\
    \        edges.emplace_back(v, u, std::numeric_limits<Cap>::max());\n    }\n\n\
    \    /**\n     * \u9802\u70B9 v \u304C\u8D64\u8272\u306B\u306A\u308B\u3068\u5831\
    \u916C\u3092\u5F97\u308B\n     */\n    void red_reward(int v, Cap reward) {\n\
    \        assert(0 <= v && v < n && reward >= 0);\n        base += reward;\n  \
    \      edges.emplace_back(s, v, reward);\n    }\n\n    /**\n     * \u9802\u70B9\
    \ v \u304C\u9752\u8272\u306B\u306A\u308B\u3068\u5831\u916C\u3092\u5F97\u308B\n\
    \     */\n    void blue_reward(int v, Cap reward) {\n        assert(0 <= v &&\
    \ v < n && reward >= 0);\n        base += reward;\n        edges.emplace_back(v,\
    \ t, reward);\n    }\n\n    /**\n     * \u9802\u70B9 u \u3068 v \u304C\u540C\u3058\
    \u8272\u306B\u306A\u308B\u3068\u5831\u916C\u3092\u5F97\u308B\n     */\n    void\
    \ same_reward(int u, int v, Cap reward) {\n        assert(0 <= u && u < n && 0\
    \ <= v && v < n && u != v && reward >= 0);\n        base += reward;\n        edges.emplace_back(u,\
    \ v, reward);\n        edges.emplace_back(v, u, reward);\n    }\n\n    /**\n \
    \    * \u8D64\u8272\u306E\u9802\u70B9\u304C\u5B58\u5728\u3059\u308B\u3068\u30DA\
    \u30CA\u30EB\u30C6\u30A3\u3092\u53D7\u3051\u308B\n     */\n    void any_red_peanlty(int\
    \ u, int v, Cap penalty) {\n        assert(0 <= u && u < n && 0 <= v && v < n\
    \ && u != v && penalty >= 0);\n        edges.emplace_back(v, t, penalty);\n  \
    \      edges.emplace_back(u, v, penalty);\n    }\n\n    /**\n     * \u8D64\u8272\
    \u306E\u9802\u70B9\u304C\u5B58\u5728\u3059\u308B\u3068\u30DA\u30CA\u30EB\u30C6\
    \u30A3\u3092\u53D7\u3051\u308B\n     */\n    void any_red_peanlty(const std::vector<int>&\
    \ vs, Cap penalty) {\n        int u = mf_n++;\n        for (int v : vs) {\n  \
    \          assert(0 <= v && v < n);\n            edges.emplace_back(v, u, std::numeric_limits<Cap>::max());\n\
    \        }\n        edges.emplace_back(u, t, penalty);\n    }\n\n    /**\n   \
    \  * \u9752\u8272\u306E\u9802\u70B9\u304C\u5B58\u5728\u3059\u308B\u3068\u30DA\u30CA\
    \u30EB\u30C6\u30A3\u3092\u53D7\u3051\u308B\n     */\n    void any_blue_penalty(int\
    \ u, int v, Cap penalty) {\n        assert(0 <= u && u < n && 0 <= v && v < n\
    \ && u != v && penalty >= 0);\n        edges.emplace_back(s, u, penalty);\n  \
    \      edges.emplace_back(u, v, penalty);\n    }\n\n    /**\n     * \u9752\u8272\
    \u306E\u9802\u70B9\u304C\u5B58\u5728\u3059\u308B\u3068\u30DA\u30CA\u30EB\u30C6\
    \u30A3\u3092\u53D7\u3051\u308B\n     */\n    void any_blue_penalty(const std::vector<int>&\
    \ vs, Cap penalty) {\n        int u = mf_n++;\n        for (int v : vs) {\n  \
    \          assert(0 <= v && v < n);\n            edges.emplace_back(u, v, std::numeric_limits<Cap>::max());\n\
    \        }\n        edges.emplace_back(s, u, penalty);\n    }\n\n    /**\n   \
    \  * \u9802\u70B9 u \u3068 v \u304C\u8D64\u8272\u306B\u306A\u308B\u3068\u5831\u916C\
    \u3092\u5F97\u308B\n     */\n    void all_red_reward(int u, int v, Cap reward)\
    \ {\n        assert(0 <= u && u < n && 0 <= v && v < n && u != v && reward >=\
    \ 0);\n        base += reward;\n        edges.emplace_back(s, u, reward);\n  \
    \      edges.emplace_back(u, v, reward);\n    }\n\n    /**\n     * \u3059\u3079\
    \u3066\u306E\u9802\u70B9\u304C\u8D64\u306B\u306A\u308B\u3068\u5831\u916C\u3092\
    \u5F97\u308B\n     */\n    void all_red_reward(const std::vector<int>& vs, Cap\
    \ reward) {\n        base += reward;\n        int u = mf_n++;\n        for (int\
    \ v : vs) {\n            assert(0 <= v && v < n);\n            edges.emplace_back(u,\
    \ v, std::numeric_limits<Cap>::max());\n        }\n        edges.emplace_back(s,\
    \ u, reward);\n    }\n\n    /**\n     * \u9802\u70B9 u \u3068 v \u304C\u9752\u8272\
    \u306B\u306A\u308B\u3068\u5831\u916C\u3092\u5F97\u308B\n     */\n    void all_blue_reward(int\
    \ u, int v, Cap reward) {\n        assert(0 <= u && u < n && 0 <= v && v < n &&\
    \ u != v && reward >= 0);\n        base += reward;\n        edges.emplace_back(v,\
    \ t, reward);\n        edges.emplace_back(u, v, reward);\n    }\n\n    /**\n \
    \    * \u3059\u3079\u3066\u306E\u9802\u70B9\u304C\u9752\u306B\u306A\u308B\u3068\
    \u5831\u916C\u3092\u5F97\u308B\n     */\n    void all_blue_reward(const std::vector<int>&\
    \ vs, Cap reward) {\n        base += reward;\n        int u = mf_n++;\n      \
    \  for (int v : vs) {\n            assert(0 <= v && v < n);\n            edges.emplace_back(v,\
    \ u, std::numeric_limits<Cap>::max());\n        }\n        edges.emplace_back(u,\
    \ t, reward);\n    }\n\n    /**\n     * \u5831\u916C\u306E\u6700\u5927\u5024\u3092\
    \u6C42\u3081\u308B\n     */\n    Cap solve() {\n        g = atcoder::mf_graph<Cap>(mf_n);\n\
    \        for (const auto& [u, v, cost] : edges) {\n            g.add_edge(u, v,\
    \ cost);\n        }\n        return base - g.flow(s, t);\n    }\n\n    std::vector<bool>\
    \ red_selection() {\n        auto selection = g.min_cut(s);\n        selection.resize(n);\n\
    \        return selection;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/ProjectSelectionProblem.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/ProjectSelectionProblem.hpp
layout: document
redirect_from:
- /library/flow/ProjectSelectionProblem.hpp
- /library/flow/ProjectSelectionProblem.hpp.html
title: flow/ProjectSelectionProblem.hpp
---
