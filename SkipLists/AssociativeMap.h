#ifndef ASSOCIATIVE_MAP_H
#define ASSOCIATIVE_MAP_H

template <class key_t, class val_t>
class AssociativeMap
{
  public:
   //Virtual destructor (does nothing)
   virtual ~AssociativeMap() { }

   //Inserts the given key/value pair.
   //If the key is already in the map, changes its
   //associated value to the given value.
   virtual void insert(const key_t& key, const val_t& value) = 0;

   //Removes the given key and its associated value
   //from the map. Does nothing if the key is not
   //in the map.
   virtual void remove(const key_t& key) = 0;

   //Returns true if the map contains the given key
   //(false otherwise)
   virtual bool contains(const key_t& key) = 0;

   //Finds the given key in the map and returns its
   //associated value. If the key is not in the
   //map, adds it and associates it with the result
   //of the default constructor of val_t, and returns
   //that value.
   virtual const val_t& find(const key_t& key) = 0;

   //Returns the number of key/value pairs in the map.
   virtual int getSize() = 0;

   //Returns true if the map is empty (false otherwise).
   virtual bool isEmpty() = 0;
};

#endif
