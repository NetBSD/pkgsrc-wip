$NetBSD$

# Portability

--- core/profile.h.orig	2018-07-18 09:45:21 UTC
+++ core/profile.h
@@ -17,6 +17,7 @@ Authors: Sebastian Deorowicz, Agnieszka 
 #include <tuple>
 #include <array>
 #include <algorithm>
+#include <cstring>
 
 #include "../libs/asmlib.h"
 
@@ -49,7 +50,7 @@ public:
 
 	void set_zeros(void)
 	{
-		A_memset(raw_data, 0, n_rows * n_cols);
+		memset(raw_data, 0, n_rows * n_cols);
 	}
 
 	unsigned char *get_row(size_t row_id)
@@ -397,4 +398,4 @@ public:
 };
 
 
-#endif
\ No newline at end of file
+#endif
