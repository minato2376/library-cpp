template <typename T> struct RangeSet : set<pair<T, T>> {
    T insert_range(T l, T r) {
        assert(l < r);
        T increased_length = 0;
        auto it = this->lower_bound(make_pair(l, r));
        while (it != this->end() && it->first <= r) {
            r = max(r, it->second);
            increased_length -= it->second - it->first;
            it = this->erase(it);
        }
        if (it != this->begin() && prev(it)->second >= l) {
            it = prev(it);
            l = min(l, it->first);
            r = max(r, it->second);
            increased_length -= it->second - it->first;
            it = this->erase(it);
        }
        increased_length += r - l;
        this->emplace_hint(it, make_pair(l, r));
        return increased_length;
    }

    T insert_point(T x) {
        return insert_range(x, x + 1);
    }

    T erase_range(T l, T r) {
        assert(l < r);
        T decreased_length = r - l - add(l, r);
        auto it =
            prev(this->upper_bound(make_pair(l, numeric_limits<T>::max())));
        auto [new_l, new_r] = *it;
        if (new_l < l) this->emplace_hint(it, make_pair(new_l, l));
        it = this->erase(it);
        if (new_r > r) this->emplace_hint(it, make_pair(r, new_r));
        return decreased_length;
    }

    T erase_point(T x) {
        return erase_range(x, x + 1);
    }

    auto contains_range(T l, T r) const {
        assert(l < r);
        auto it = this->upper_bound(make_pair(l, numeric_limits<T>::max()));
        if (it == this->begin()) return this->end();
        it = prev(it);
        return (it->first <= l && r <= it->second ? it : this->end());
    }

    auto contains_point(T x) const {
        return contains_range(x, x + 1);
    }

    T mex() const {
        assert(this->empty() || this->begin()->first >= 0);
        if (this->empty()) return 0;
        return this->begin()->first == 0 ? this->begin()->second : 0;
    }

#ifdef MINATO_LOCAL
    friend ostream& operator<<(ostream& os, RangeSet r) {
        for (auto it = r.begin(); it != r.end(); it = next(it)) {
            if (it != r.begin()) os << ", ";
            os << *it;
        }
        return os;
    }
#endif
};