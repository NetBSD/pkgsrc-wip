$NetBSD$

Add NetBSD support bits.

--- src/System_Info.cpp.orig	2016-05-31 12:34:02.000000000 +0000
+++ src/System_Info.cpp
@@ -2732,6 +2732,73 @@ bool System_Info::Update_Host_USB()
 
 #endif // FreeBSD
 
+#ifdef Q_OS_NETBSD
+
+#include <uvm/uvm_extern.h>
+#include <sys/sysctl.h>
+#include <QDir>
+#include <QFileInfoList>
+
+void System_Info::Get_Free_Memory_Size( int &allRAM, int &freeRAM )
+{
+	int mib[] = { CTL_VM, VM_UVMEXP2 };
+	struct uvmexp_sysctl uvmexp;
+	size_t ssize;
+
+	ssize = sizeof(uvmexp);
+	memset(&uvmexp, 0, ssize);
+
+	if (sysctl(mib, 2, &uvmexp, &ssize, NULL, 0) < 0)
+	{
+		AQError( "void  System_Info::Get_Free_Memory_Size( int &allRAM, int &freeRAM )",
+				 "Cannot Get Information on Memory! (vm.uvmexp2)" );
+	}
+
+	allRAM = (uvmexp.npages * uvmexp.pagesize / 1024) / 1024;
+	freeRAM = (uvmexp.free * uvmexp.pagesize / 1024) / 1024;
+}
+
+QStringList System_Info::Get_Host_FDD_List()
+{
+	// Find Floppy's
+	QDir dev_dir( "/dev/" );
+	QFileInfoList devices = dev_dir.entryInfoList( QStringList("fd*"), QDir::System, QDir::Name );
+	
+	QStringList tmp_list;
+	
+	for( int d = 0; d < devices.count(); ++d )
+	{
+		tmp_list << devices[d].absoluteFilePath();
+	}
+	
+	return tmp_list;
+}
+
+QStringList System_Info::Get_Host_CDROM_List()
+{
+	// Find CD-ROM's
+	QDir dev_dir( "/dev/" );
+	QFileInfoList devices = dev_dir.entryInfoList( QStringList("cd*"), QDir::System, QDir::Name );
+	
+	QStringList tmp_list;
+	
+	for( int d = 0; d < devices.count(); ++d )
+	{
+		tmp_list << devices[d].absoluteFilePath();
+	}
+	
+	return tmp_list;
+}
+
+bool System_Info::Update_Host_USB()
+{
+	AQError( "System_Info::Update_Host_USB()",
+			 "Not implemented!" );
+	return false;
+}
+
+#endif // NetBSD
+
 #ifdef Q_OS_WIN32
 
 #include <windows.h>
