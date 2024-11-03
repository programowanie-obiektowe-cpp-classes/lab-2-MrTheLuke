#pragma once

#include "Resource.hpp"
#include <memory> // Dla std::unique_ptr

class ResourceManager
{
private:
    // Wskaünik do zasobu
    std::unique_ptr< Resource > zasob;

public:
    // Konstruktor domyúlny
    ResourceManager() : zasob(std::make_unique< Resource >()) {}

    // Konstruktor kopiujπcy
    ResourceManager(const ResourceManager& other)
        : zasob(other.zasob ? std::make_unique< Resource >(*other.zasob) : nullptr)
    {}

    // Operator przypisania kopiujπcy
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            zasob = other.zasob ? std::make_unique< Resource >(*other.zasob) : nullptr;
        }
        return *this;
    }

    // Destruktor
    ~ResourceManager() = default;

    // Metoda get - zwraca wynik zawo≥ania metody get obiektu Resource
    // Sprawdza, czy zasÛb istnieje
    double get() { 
        return zasob ? zasob->get() : 0.0; 
    }
};
