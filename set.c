#include "set.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

Set set_empty(void) {
    Set s = '\0';
    s = s & 0x00;
    return s;
}
//not in header but in this file?!
Set set_universal(void) {
    Set u = 0xFF;
    return u;
}

bool set_member(Set s, int x) {
    Set mem = s | (0x01 << x);
    if (mem == s) {
        return true;
    }
    return false;
}

Set set_insert(Set s, int x) {
    s = s | (0x01 << x);
    return s;
}

Set set_remove(Set s, int x) {
    s = s & ~(0x01 << x);
    return s;
}

Set set_union(Set s, Set t) {
    Set u = s | t;
    return u;
}

Set set_intersect(Set s, Set t) {
    Set i = s & t;
    return i;
}

Set set_difference(Set s, Set t) {
    Set diff = set_intersect(s, t);
    s = s & ~diff;
    return s;
}

Set set_complement(Set s) {
    return ~s;
}
