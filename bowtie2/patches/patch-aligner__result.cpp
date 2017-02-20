--- aligner_result.cpp.orig	2017-02-19 18:40:54.398991000 -0600
+++ aligner_result.cpp	2017-02-19 18:41:14.093250000 -0600
@@ -1130,7 +1130,7 @@ bool AlnFlags::printYF(BTString& o, bool
 	else if(!nfilt_  ) flag = "NS";
 	else if(!scfilt_ ) flag = "SC";
 	else if(!qcfilt_ ) flag = "QC";
-	if(flag > 0) {
+	if(*flag != '\0') {
 		if(!first) o.append('\t');
 		o.append("YF:Z:");
 		o.append(flag);
