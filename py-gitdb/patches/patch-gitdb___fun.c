$NetBSD$

PyMODINIT_FUNC usually is a "PyObject*" and clang does not like
functions of that type returning nothing.
https://github.com/gitpython-developers/gitdb/issues/40

--- gitdb/_fun.c.orig	2014-05-04 19:42:31.000000000 +0000
+++ gitdb/_fun.c
@@ -89,19 +89,20 @@ static PyMethodDef py_fun[] = {
 };
 
 #ifndef PyMODINIT_FUNC	/* declarations for DLL import/export */
-#define PyMODINIT_FUNC void
+#define PyMODINIT_FUNC void*
 #endif
 PyMODINIT_FUNC init_perf(void)
 {
 	PyObject *m;
 
 	if (PyType_Ready(&DeltaChunkListType) < 0)
-		return;
+		return NULL;
 	
 	m = Py_InitModule3("_perf", py_fun, NULL);
 	if (m == NULL)
-		return;
+		return NULL;
 	
 	Py_INCREF(&DeltaChunkListType);
 	PyModule_AddObject(m, "DeltaChunkList", (PyObject *)&DeltaChunkListType);
+	return NULL;
 }
