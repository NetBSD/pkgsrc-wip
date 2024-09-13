$NetBSD$

Patch by David Torres Sanchez borrowed from nix based distro on Linux

--- lemon/bits/array_map.h.orig	2014-07-07 14:40:24.917315535 +0000
+++ lemon/bits/array_map.h
@@ -75,6 +75,7 @@ namespace lemon {
     typedef typename Notifier::ObserverBase Parent;
 
     typedef std::allocator<Value> Allocator;
+    typedef std::allocator_traits<std::allocator<Value>> AllocatorTraits;
 
   public:
 
@@ -87,8 +88,8 @@ namespace lemon {
       Notifier* nf = Parent::notifier();
       Item it;
       for (nf->first(it); it != INVALID; nf->next(it)) {
-        int id = nf->id(it);;
-        allocator.construct(&(values[id]), Value());
+        int id = nf->id(it);
+        AllocatorTraits::construct(allocator, &(values[id]), Value());
       }
     }
 
@@ -101,8 +102,8 @@ namespace lemon {
       Notifier* nf = Parent::notifier();
       Item it;
       for (nf->first(it); it != INVALID; nf->next(it)) {
-        int id = nf->id(it);;
-        allocator.construct(&(values[id]), value);
+        int id = nf->id(it);
+        AllocatorTraits::construct(allocator, &(values[id]), value);
       }
     }
 
@@ -120,8 +121,8 @@ namespace lemon {
       Notifier* nf = Parent::notifier();
       Item it;
       for (nf->first(it); it != INVALID; nf->next(it)) {
-        int id = nf->id(it);;
-        allocator.construct(&(values[id]), copy.values[id]);
+        int id = nf->id(it);
+        AllocatorTraits::construct(allocator, &(values[id]), copy.values[id]);
       }
     }
 
@@ -216,17 +217,17 @@ namespace lemon {
         Value* new_values = allocator.allocate(new_capacity);
         Item it;
         for (nf->first(it); it != INVALID; nf->next(it)) {
-          int jd = nf->id(it);;
+          int jd = nf->id(it);
           if (id != jd) {
-            allocator.construct(&(new_values[jd]), values[jd]);
-            allocator.destroy(&(values[jd]));
+            AllocatorTraits::construct(allocator, &(new_values[jd]), values[jd]);
+            AllocatorTraits::destroy(allocator, &(values[jd]));
           }
         }
         if (capacity != 0) allocator.deallocate(values, capacity);
         values = new_values;
         capacity = new_capacity;
       }
-      allocator.construct(&(values[id]), Value());
+      AllocatorTraits::construct(allocator, &(values[id]), Value());
     }
 
     // \brief Adds more new keys to the map.
@@ -260,8 +261,8 @@ namespace lemon {
             }
           }
           if (found) continue;
-          allocator.construct(&(new_values[id]), values[id]);
-          allocator.destroy(&(values[id]));
+          AllocatorTraits::construct(allocator, &(new_values[id]), values[id]);
+          AllocatorTraits::destroy(allocator, &(values[id]));
         }
         if (capacity != 0) allocator.deallocate(values, capacity);
         values = new_values;
@@ -269,7 +270,7 @@ namespace lemon {
       }
       for (int i = 0; i < int(keys.size()); ++i) {
         int id = nf->id(keys[i]);
-        allocator.construct(&(values[id]), Value());
+        AllocatorTraits::construct(allocator, &(values[id]), Value());
       }
     }
 
@@ -279,7 +280,7 @@ namespace lemon {
     // and it overrides the erase() member function of the observer base.
     virtual void erase(const Key& key) {
       int id = Parent::notifier()->id(key);
-      allocator.destroy(&(values[id]));
+      AllocatorTraits::destroy(allocator, &(values[id]));
     }
 
     // \brief Erase more keys from the map.
@@ -289,7 +290,7 @@ namespace lemon {
     virtual void erase(const std::vector<Key>& keys) {
       for (int i = 0; i < int(keys.size()); ++i) {
         int id = Parent::notifier()->id(keys[i]);
-        allocator.destroy(&(values[id]));
+        AllocatorTraits::destroy(allocator, &(values[id]));
       }
     }
 
@@ -302,8 +303,8 @@ namespace lemon {
       allocate_memory();
       Item it;
       for (nf->first(it); it != INVALID; nf->next(it)) {
-        int id = nf->id(it);;
-        allocator.construct(&(values[id]), Value());
+        int id = nf->id(it);
+        AllocatorTraits::construct(allocator, &(values[id]), Value());
       }
     }
 
@@ -317,7 +318,7 @@ namespace lemon {
         Item it;
         for (nf->first(it); it != INVALID; nf->next(it)) {
           int id = nf->id(it);
-          allocator.destroy(&(values[id]));
+          AllocatorTraits::destroy(allocator, &(values[id]));
         }
         allocator.deallocate(values, capacity);
         capacity = 0;
