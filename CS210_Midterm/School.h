#pragma once
#include <string>
#include "Utils.cpp"

struct School {
    string name = "";
    string address = "";
    string city = "";
    string state = "";
    string county = "";

    School* next = nullptr;

    School() {

    }

    School(School* other) {
        name = other->name;
        address = other->address;
        city = other->city;
        state = other->state;
        county = other->county;
    }

    void print() {
        println("Name: " + name);
        println("Address: " + address);
        println("City: " + city);
        println("County: " + county);
        println("State: " + state);
    }
};
