$NetBSD$

* Include missing header for xmlnode_str.
* Header files of pkgsrc PostgreSQL are not in postgresql/ directory.
* Reorder xdbsql_struct.
* Change function signature.
* Add missing enumeration values in switch.
* Add parentheses for test condition used as boolean value.

--- xdb_sql/xdb_sql.cc.orig	2019-09-29 18:37:09.000000000 +0000
+++ xdb_sql/xdb_sql.cc
@@ -24,6 +24,7 @@
 
 #include <jabberd.h>
 
+#include <expat.hh>
 #include <namespaces.hh>
 
 #include <list>
@@ -40,7 +41,7 @@
 #endif
 
 #ifdef HAVE_POSTGRESQL
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 #endif
 
 /**
@@ -91,12 +92,6 @@ typedef struct xdbsql_struct {
     std::map<std::string, _xdbsql_ns_def>
         namespace_defs; /**< definitions of queries for the different namespaces
                          */
-    char *onconnect; /**< SQL query that should be executed after we connected
-                        to the database server */
-    xht namespace_prefixes;     /**< prefixes for the namespaces (key = prefix,
-                                   value = ns_iri) */
-    xht std_namespace_prefixes; /**< prefixes used by the component itself for
-                                   the namespaces */
 #ifdef HAVE_MYSQL
     int use_mysql;        /**< if we want to use the mysql driver */
     MYSQL *mysql;         /**< our database handle */
@@ -114,6 +109,12 @@ typedef struct xdbsql_struct {
     PGconn *postgresql;        /**< our postgresql connection handle */
     char *postgresql_conninfo; /**< settings used to connect to postgresql */
 #endif
+    char *onconnect; /**< SQL query that should be executed after we connected
+                        to the database server */
+    xht namespace_prefixes;     /**< prefixes for the namespaces (key = prefix,
+                                   value = ns_iri) */
+    xht std_namespace_prefixes; /**< prefixes used by the component itself for
+                                   the namespaces */
 } * xdbsql, _xdbsql;
 
 /* forward declaration */
@@ -414,7 +415,7 @@ static int xdb_sql_execute_mysql(instanc
  * @return 0 on success, non zero on failure
  */
 #ifdef HAVE_POSTGRESQL
-static int xdb_sql_execute_postgresql(instance i, xdbsql xq, char *query,
+static int xdb_sql_execute_postgresql(instance i, xdbsql xq, char const *query,
                                       xmlnode xmltemplate, xmlnode result) {
     PGresult *res = NULL;
     ExecStatusType status = static_cast<ExecStatusType>(0);
@@ -452,6 +453,7 @@ static int xdb_sql_execute_postgresql(in
         case PGRES_EMPTY_QUERY:
         case PGRES_BAD_RESPONSE:
         case PGRES_FATAL_ERROR:
+        case PGRES_NONFATAL_ERROR:
             log_warn(i->id, "%s: %s", PQresStatus(status),
                      PQresultErrorMessage(res));
             PQclear(res);
@@ -459,6 +461,9 @@ static int xdb_sql_execute_postgresql(in
         case PGRES_COMMAND_OK:
         case PGRES_COPY_OUT:
         case PGRES_COPY_IN:
+        case PGRES_COPY_BOTH:
+        case PGRES_SINGLE_TUPLE:
+        case PGRES_TUPLES_OK:
             PQclear(res);
             return 0;
     }
@@ -473,8 +478,8 @@ static int xdb_sql_execute_postgresql(in
         new_instance = xmlnode_dup_pool(result->p, xmltemplate);
 
         /* find variables in the template and replace them with values */
-        while (variable = xdb_sql_find_node_recursive(new_instance, "value",
-                                                      NS_JABBERD_XDBSQL)) {
+        while ((variable = xdb_sql_find_node_recursive(new_instance, "value",
+                                                      NS_JABBERD_XDBSQL))) {
             xmlnode parent = xmlnode_get_parent(variable);
             int value =
                 j_atoi(xmlnode_get_attrib_ns(variable, "value", NULL), 0);
