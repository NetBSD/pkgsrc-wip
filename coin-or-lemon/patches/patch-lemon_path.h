$NetBSD$

Patch by David Torres Sanchez borrowed from nix based distro on Linux

--- lemon/path.h.orig	2014-07-07 14:40:24.963315795 +0000
+++ lemon/path.h
@@ -393,7 +393,7 @@ namespace lemon {
       data.resize(len);
       int index = 0;
       for (typename CPath::ArcIt it(path); it != INVALID; ++it) {
-        data[index] = it;;
+        data[index] = it;
         ++index;
       }
     }
@@ -405,7 +405,7 @@ namespace lemon {
       int index = len;
       for (typename CPath::RevArcIt it(path); it != INVALID; ++it) {
         --index;
-        data[index] = it;;
+        data[index] = it;
       }
     }
 
@@ -448,7 +448,9 @@ namespace lemon {
 
     Node *first, *last;
 
-    std::allocator<Node> alloc;
+  private:
+    typedef std::allocator<Node> Allocator;
+    typedef std::allocator_traits<std::allocator<Node>> AllocatorTraits;
 
   public:
 
@@ -582,8 +584,8 @@ namespace lemon {
     void clear() {
       while (first != 0) {
         last = first->next;
-        alloc.destroy(first);
-        alloc.deallocate(first, 1);
+        AllocatorTraits::destroy(_allocator, first);
+        _allocator.deallocate(first, 1);
         first = last;
       }
     }
@@ -595,8 +597,8 @@ namespace lemon {
 
     /// \brief Add a new arc before the current path
     void addFront(const Arc& arc) {
-      Node *node = alloc.allocate(1);
-      alloc.construct(node, Node());
+      Node *node = _allocator.allocate(1);
+      AllocatorTraits::construct(_allocator, node, Node());
       node->prev = 0;
       node->next = first;
       node->arc = arc;
@@ -617,8 +619,8 @@ namespace lemon {
       } else {
         last = 0;
       }
-      alloc.destroy(node);
-      alloc.deallocate(node, 1);
+      AllocatorTraits::destroy(_allocator, node);
+      _allocator.deallocate(node, 1);
     }
 
     /// \brief The last arc of the path.
@@ -628,8 +630,8 @@ namespace lemon {
 
     /// \brief Add a new arc behind the current path.
     void addBack(const Arc& arc) {
-      Node *node = alloc.allocate(1);
-      alloc.construct(node, Node());
+      Node *node = _allocator.allocate(1);
+      AllocatorTraits::construct(_allocator, node, Node());
       node->next = 0;
       node->prev = last;
       node->arc = arc;
@@ -650,8 +652,8 @@ namespace lemon {
       } else {
         first = 0;
       }
-      alloc.destroy(node);
-      alloc.deallocate(node, 1);
+      AllocatorTraits::destroy(_allocator, node);
+      _allocator.deallocate(node, 1);
     }
 
     /// \brief Splice a path to the back of the current path.
@@ -766,6 +768,9 @@ namespace lemon {
       }
     }
 
+  private:
+    Allocator _allocator;
+
   };
 
   /// \brief A structure for representing directed paths in a digraph.
