///
/// Find a local minimum in a n x n grid - O(n)
///

#ifndef cf_algo_gridlocalmin
#define cf_algo_gridlocalmin

namespace algo {
    size_t FindMin(uint32_t *data, size_t nb, size_t start, size_t stop, size_t w) {
        uint32_t valMin = data[start];
        size_t i = start + 1, pos = start, sl = start;
        while (i <= stop) {
            if (data[i] < valMin) { valMin = data[i]; pos = i; }
            if (++i == (sl + w)) { sl += nb; i = sl; }
        }
        return pos;
    }
    uint32_t GridLocalMinLines(uint32_t *data, size_t nb, size_t start, size_t stop) {
        size_t mpos, tpos, h = (stop - start + 1) / nb;
        if (h < 4) return FindMin(data, nb, start, stop, 0);
        size_t m = nb * (h / 2);
        tpos = start + m + nb;
        mpos = FindMin(data, nb, tpos - nb, tpos + nb - 1, 0);
        if (mpos >= tpos) start = tpos;
        else stop = tpos - 1;
        return algo::GridLocalMinLines(data, nb, start, stop);
    }
    uint32_t GridLocalMinLines3(uint32_t *data, size_t nb, size_t start, size_t stop) {
        size_t mpos, tpos, h = (stop - start + 1) / nb;
        if (h < 11) return FindMin(data, nb, start, stop, 0);
        size_t m = nb * (h / 4);
        tpos = start + m + nb;
        mpos = FindMin(data, nb, tpos - nb, tpos + nb - 1, 0);
        if (mpos < tpos) return algo::GridLocalMinLines3(data, nb, start, tpos - 1);
        start = tpos;
        tpos = start + m + m + nb;
        mpos = FindMin(data, nb, tpos - nb, tpos + nb - 1, 0);
        if (mpos >= tpos) return algo::GridLocalMinLines3(data, nb, tpos, stop);
        stop = tpos -  1;
        tpos = start + m + nb;
        mpos = FindMin(data, nb, start + m, tpos + nb - 1, 0);
        if (mpos < tpos) return algo::GridLocalMinLines(data, nb, start, tpos - 1);
        else return algo::GridLocalMinLines(data, nb, tpos, stop);
    }
    uint32_t GridLocalMin(uint32_t *data, size_t nb, size_t pos, size_t start, size_t stop) {
        size_t mpos, tpos, w = (stop - start + 1) % nb, h = (stop - start + 1) / nb;
        if (w == 0) w = nb;
        if (w < 8 || h < 8) return FindMin(data, nb, start, stop, w);
        size_t m = nb * (h / 2);
        tpos = start + m + nb;
        if (w == nb) mpos = FindMin(data, nb, tpos - nb, tpos + w - 1, w + w);
        else mpos = FindMin(data, nb, tpos - nb, tpos + w - 1, w);
        if (pos == (nb * nb) || data[pos] > data[mpos]) pos = mpos;
        if (pos >= tpos) start = tpos;
        else stop = start + m + w - 1;
        m = (w - 1) / 2; h = m - (w & 1);
        mpos = FindMin(data, nb, start + m, stop - h, 2);
        if (data[pos] > data[mpos]) pos = mpos;
        if (((pos - start) % nb) > m) start += m + 1;
        else stop -= h + 1;
        return algo::GridLocalMin(data, nb, pos, start, stop);
    }
}
#endif // cf_algo_gridlocalmin
