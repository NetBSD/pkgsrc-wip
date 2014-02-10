$Id: patch-Image_GraphViz.php,v 1.1 2014/02/10 21:02:01 noud4 Exp $

taken from:
http://pear.php.net/bugs/bug.php?id=20171&edit=12&patch=GraphViz.php.patch&revision=1389192687

--- Image/GraphViz.php.orig	2010-10-24 05:21:34.000000000 +0000
+++ Image/GraphViz.php
@@ -387,7 +387,7 @@ class Image_GraphViz
      * A cluster is a subgraph with a rectangle around it.
      *
      * @param string $id         ID.
-     * @param array  $title      Title.
+     * @param string $title      Title.
      * @param array  $attributes Attributes of the cluster.
      * @param string $group      ID of group to nest cluster into
      *
@@ -406,7 +406,7 @@ class Image_GraphViz
      * Adds a subgraph to the graph.
      *
      * @param string $id         ID.
-     * @param array  $title      Title.
+     * @param string $title      Title.
      * @param array  $attributes Attributes of the cluster.
      * @param string $group      ID of group to nest subgraph into
      *
@@ -933,7 +933,9 @@ class Image_GraphViz
     function _subgraph($group, &$indent)
     {
         $parsedGraph = '';
-        $nodes = $this->graph['nodes'][$group];
+        if (isset ($this->graph['nodes']["$group"]))
+            $nodes = $this->graph['nodes']["$group"];
+        else $nodes = null;
 
         if ($group !== 'default') {
             $type = null;
@@ -972,7 +974,8 @@ class Image_GraphViz
             }
         }
 
-        $parsedGraph .= $this->_nodes($nodes, $indent);
+        if ($nodes)
+            $parsedGraph .= $this->_nodes($nodes, $indent);
 
         foreach ($this->_getSubgraphs($group) as $_group) {
             $parsedGraph .= $this->_subgraph($_group, $indent);
@@ -1028,4 +1031,4 @@ class Image_GraphViz
  * c-hanging-comment-ender-p: nil
  * End:
  */
-?>
\ No newline at end of file
+?>
