#pragma once

template <typename Key, typename Value>
struct KeyValuePair {
    Key key;
    Value value;

    KeyValuePair() = default;

    explicit KeyValuePair(Key key) : key(key) {}

    KeyValuePair(Key key, Value value) : key(key), value(value) {}

    bool operator==(const KeyValuePair& other) {
        return key == other.key;
    }

    bool operator!=(const KeyValuePair& other) {
        return key != other.key;
    }

    bool operator<(const KeyValuePair& other) {
        return key < other.key;
    }

    bool operator>(const KeyValuePair& other) {
        return key > other.key;
    }

    bool operator<=(const KeyValuePair& other) {
        return key <= other.key;
    }

    bool operator>=(const KeyValuePair& other) {
        return key >= other.key;
    }

    ~KeyValuePair() = default;
};
