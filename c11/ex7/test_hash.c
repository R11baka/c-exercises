//
// Created by Alexander Voloshenko on 28.12.2020.
//

#include "hash_table.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "memcheck.h"

void testHash(void);

void testNode(void);

void testHashTableSet(void);

void tetSet(void);

int main() {
    testHash();
    testNode();
    testHashTableSet();
    tetSet();
    print_memory_leaks();
}

void testHash() {
    char *s1 = "t";
    assert(hash(s1) > 0);
    assert(hash(s1) == 116);
}

void testNode() {
    node *n = create_node("test", 11);
    assert(strcmp(n->key, "test") == 0);
    assert(n->value == 11);
    free(n);
}

void testHashTableSet() {
    int v;
    hash_table *ht = create_hash_table();
    assert(ht != NULL);
    set_value(ht, "k", 1);
    v = get_value(ht, "k");
    assert(1 == v);
    assert(get_value(ht, "key_not_exists") == 0);
    free_hash_table(ht);
}

void tetSet() {
    hash_table *ht = create_hash_table();
    assert(ht);
    set_value(ht, "aa", 2);
    assert(get_value(ht, "aa") == 2);
    set_value(ht, "aa", 3);
    assert(get_value(ht, "aa") == 3);
    print_hash_table(ht);
    free_hash_table(ht);
}
