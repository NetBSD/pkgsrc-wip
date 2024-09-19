$NetBSD$

--- plugins/DebuggerCore/unix/netbsd/DebuggerCore.cpp.orig	2017-02-19 02:09:05.311209498 +0000
+++ plugins/DebuggerCore/unix/netbsd/DebuggerCore.cpp
@@ -0,0 +1,593 @@
+/*
+Copyright (C) 2006 - 2015 Evan Teran
+                          evan.teran@gmail.com
+
+This program is free software: you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation, either version 2 of the License, or
+(at your option) any later version.
+
+This program is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with this program.  If not, see <http://www.gnu.org/licenses/>.
+*/
+
+
+// TODO(eteran): research usage of process_vm_readv, process_vm_writev
+
+#include "DebuggerCore.h"
+#include "Configuration.h"
+#include "FeatureDetect.h"
+#include "MemoryRegions.h"
+#include "PlatformCommon.h"
+#include "PlatformEvent.h"
+#include "PlatformProcess.h"
+#include "PlatformRegion.h"
+#include "PlatformState.h"
+#include "DialogMemoryAccess.h"
+#include "State.h"
+#include "edb.h"
+#include "string_hash.h"
+
+#include <QDebug>
+#include <QDir>
+#include <QSettings>
+
+#include <cerrno>
+#include <cstring>
+
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/ptrace.h>
+#include <sys/mman.h>
+#include <sys/wait.h>
+#include <cpuid.h>
+
+#include <unistd.h>
+
+namespace DebuggerCorePlugin {
+
+namespace {
+
+const edb::address_t PageSize = getpagesize();
+
+//------------------------------------------------------------------------------
+// Name: is_numeric
+// Desc: returns true if the string only contains decimal digits
+//------------------------------------------------------------------------------
+bool is_numeric(const QString &s) {
+	for(QChar ch: s) {
+		if(!ch.isDigit()) {
+			return false;
+		}
+	}
+
+	return true;
+}
+
+bool in64BitSegment() {
+	bool edbIsIn64BitSegment;
+	// Check that we're running in 64 bit segment: this can be in cases
+	// of LP64 and ILP32 programming models, so we can't rely on sizeof(void*)
+	asm(R"(
+		   .byte 0x33,0xc0 # XOR EAX,EAX
+		   .byte 0x48      # DEC EAX for 32 bit, REX prefix for 64 bit
+		   .byte 0xff,0xc0 # INC EAX for 32 bit, INC RAX due to REX.W in 64 bit
+		 )":"=a"(edbIsIn64BitSegment));
+	return edbIsIn64BitSegment;
+}
+
+bool os64Bit(bool edbIsIn64BitSegment) {
+	bool osIs64Bit;
+	if(edbIsIn64BitSegment)
+		osIs64Bit=true;
+	else {
+		// We want to be really sure the OS is 32 bit, so we can't rely on such easy
+		// to (even unintentionally) fake mechanisms as uname(2) (e.g. see setarch(8))
+		asm(R"(.intel_syntax noprefix
+			   mov eax,cs
+			   cmp ax,0x23 # this value is set for 32-bit processes on 64-bit kernel
+			   mov ah,0    # not sure this is really needed: usually the compiler will do
+						   # MOVZX EAX,AL, but we have to be certain the result is correct
+			   sete al
+			   .att_syntax # restore default syntax
+			   )":"=a"(osIs64Bit));
+	}
+	return osIs64Bit;
+}
+
+
+
+
+}
+
+//------------------------------------------------------------------------------
+// Name: DebuggerCore
+// Desc: constructor
+//------------------------------------------------------------------------------
+DebuggerCore::DebuggerCore() :
+	binary_info_(nullptr),
+	process_(0),
+	pointer_size_(sizeof(void*)),
+	edbIsIn64BitSegment(in64BitSegment()),
+	osIs64Bit(os64Bit(edbIsIn64BitSegment)),
+	USER_CS_32(osIs64Bit?0x23:0x73),
+	USER_CS_64(osIs64Bit?0x33:0xfff8), // RPL 0 can't appear in user segment registers, so 0xfff8 is safe
+	USER_SS(osIs64Bit?0x2b:0x7b)
+{
+	qDebug() << "EDB is in" << (edbIsIn64BitSegment?"64":"32") << "bit segment";
+	qDebug() << "OS is" << (osIs64Bit?"64":"32") << "bit";
+}
+
+//------------------------------------------------------------------------------
+// Name: has_extension
+// Desc:
+//------------------------------------------------------------------------------
+bool DebuggerCore::has_extension(quint64 ext) const {
+
+	const auto mmxHash=edb::string_hash("MMX");
+	const auto xmmHash=edb::string_hash("XMM");
+	const auto ymmHash=edb::string_hash("YMM");
+	if(EDB_IS_64_BIT && (ext==xmmHash || ext==mmxHash))
+		return true;
+
+	quint32 eax;
+	quint32 ebx;
+	quint32 ecx;
+	quint32 edx;
+	__cpuid(1, eax, ebx, ecx, edx);
+
+	switch(ext) {
+	case mmxHash:
+		return (edx & bit_MMX);
+	case xmmHash:
+		return (edx & bit_SSE);
+	case ymmHash:
+	{
+		// Check OSXSAVE and AVX feature flags
+		if((ecx&0x18000000)!=0x18000000)
+			return false;
+		// Get XCR0, must be exactly after OSXSAVE feature check, otherwise #UD
+		asm volatile("xgetbv" : "=a"(eax),"=d"(edx) : "c"(0));
+		// Check that the OS has enabled XMM and YMM state support
+		if((eax&0x6)!=0x6)
+			return false;
+		return true;
+	}
+	default:
+		return false;
+	}
+
+	return false;
+}
+
+//------------------------------------------------------------------------------
+// Name: page_size
+// Desc: returns the size of a page on this system
+//------------------------------------------------------------------------------
+edb::address_t DebuggerCore::page_size() const {
+	return PageSize;
+}
+
+std::size_t DebuggerCore::pointer_size() const {
+	return pointer_size_;
+}
+
+//------------------------------------------------------------------------------
+// Name: ~DebuggerCore
+// Desc: destructor
+//------------------------------------------------------------------------------
+DebuggerCore::~DebuggerCore() {
+	end_debug_session();
+}
+
+//------------------------------------------------------------------------------
+// Name: ptrace_getsiginfo
+// Desc:
+//------------------------------------------------------------------------------
+long DebuggerCore::ptrace_getsiginfo(edb::pid_t pid, ptrace_siginfo_t *siginfo) {
+	Q_ASSERT(siginfo != 0);
+	return ptrace(PT_GET_SIGINFO, pid, siginfo, sizeof(struct ptrace_siginfo));
+}
+
+//------------------------------------------------------------------------------
+// Name: ptrace_traceme
+// Desc:
+//------------------------------------------------------------------------------
+long DebuggerCore::ptrace_traceme() {
+	return ptrace(PT_TRACE_ME, 0, NULL, 0);
+}
+
+//------------------------------------------------------------------------------
+// Name: ptrace_continue
+// Desc:
+//------------------------------------------------------------------------------
+long DebuggerCore::ptrace_continue(edb::pid_t pid, long status) {
+	Q_ASSERT(pid != 0);
+	return ptrace(PT_CONTINUE, pid, (void *)1, status);
+}
+
+//------------------------------------------------------------------------------
+// Name: ptrace_step
+// Desc:
+//------------------------------------------------------------------------------
+long DebuggerCore::ptrace_step(edb::pid_t pid, long status) {
+	Q_ASSERT(pid != 0);
+	return ptrace(PT_STEP, pid, (void *)1, status);
+}
+
+//------------------------------------------------------------------------------
+// Name: handle_event
+// Desc:
+//------------------------------------------------------------------------------
+IDebugEvent::const_pointer DebuggerCore::handle_event(edb::pid_t pid, int status) {
+
+	// was it a thread exit event?
+	if(WIFEXITED(status)) {
+		threads_.clear();
+		return nullptr;
+	}
+
+	auto e = std::make_shared<PlatformEvent>();
+
+	e->pid_    = pid;
+	e->status_ = status;
+	ptrace_getsiginfo(pid, &e->siginfo_);
+
+	return e;
+}
+
+//------------------------------------------------------------------------------
+// Name: wait_debug_event
+// Desc: waits for a debug event, msecs is a timeout
+//      it will return false if an error or timeout occurs
+//------------------------------------------------------------------------------
+IDebugEvent::const_pointer DebuggerCore::wait_debug_event(int msecs) {
+
+	if(process_) {
+		if(!native::wait_for_sigchld(msecs)) {
+			int status;
+			const edb::pid_t wpid = native::waitpid(pid(), &status, __WALL | WNOHANG);
+			if(wpid > 0) {
+				return handle_event(pid(), status);
+			}
+		}
+	}
+	return nullptr;
+}
+
+//------------------------------------------------------------------------------
+// Name: attach
+// Desc:
+//------------------------------------------------------------------------------
+QString DebuggerCore::attach(edb::pid_t pid) {
+
+	static const QString statusOK{};
+
+	end_debug_session();
+
+	lastMeansOfCapture=MeansOfCapture::Attach;
+
+	// create this, so the threads created can refer to it
+	process_ = new PlatformProcess(this, pid);
+
+	int lastErr=ptrace(PT_ATTACH, pid, NULL, 0); // Fail early if we are going to
+	if(lastErr) return std::strerror(lastErr);
+
+	pid_            = pid;
+	binary_info_    = edb::v1::get_binary_info(edb::v1::primary_code_region());
+	detectDebuggeeBitness();
+	return statusOK;
+}
+
+//------------------------------------------------------------------------------
+// Name: detach
+// Desc:
+//------------------------------------------------------------------------------
+void DebuggerCore::detach() {
+	if(process_) {
+
+		clear_breakpoints();
+
+		ptrace(PT_DETACH, pid(), NULL, 0);
+
+		delete process_;
+		process_ = nullptr;
+
+		reset();
+	}
+}
+
+//------------------------------------------------------------------------------
+// Name: kill
+// Desc:
+//------------------------------------------------------------------------------
+void DebuggerCore::kill() {
+	if(attached()) {
+		clear_breakpoints();
+
+		ptrace(PT_KILL, pid(), NULL, 0);
+
+		native::waitpid(pid(), 0, __WALL);
+
+		delete process_;
+		process_ = 0;
+
+		reset();
+	}
+}
+
+void DebuggerCore::detectDebuggeeBitness() {
+#if defined(__i386__)
+	qDebug() << "Debuggee is now 32 bit";
+	CapstoneEDB::init(CapstoneEDB::Architecture::ARCH_X86);
+#elif defined(__x86_64__)
+	qDebug() << "Debuggee is now 64 bit";
+	CapstoneEDB::init(CapstoneEDB::Architecture::ARCH_AMD64);
+#else
+#error portme
+#endif
+}
+
+//------------------------------------------------------------------------------
+// Name: open
+// Desc:
+//------------------------------------------------------------------------------
+QString DebuggerCore::open(const QString &path, const QString &cwd, const QList<QByteArray> &args, const QString &tty) {
+
+	static const QString statusOK{};
+
+	end_debug_session();
+
+	lastMeansOfCapture=MeansOfCapture::Launch;
+
+	static std::size_t sharedMemSize=getpagesize();
+	const auto sharedMem=static_cast<QChar*>(::mmap(nullptr,sharedMemSize,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0));
+	std::memset(sharedMem,0,sharedMemSize);
+
+	switch(pid_t pid = fork()) {
+	case 0:
+	{
+		// we are in the child now...
+
+		// set ourselves (the child proc) up to be traced
+		ptrace_traceme();
+
+		// redirect it's I/O
+		if(!tty.isEmpty()) {
+			FILE *const std_out = freopen(qPrintable(tty), "r+b", stdout);
+			FILE *const std_in  = freopen(qPrintable(tty), "r+b", stdin);
+			FILE *const std_err = freopen(qPrintable(tty), "r+b", stderr);
+
+			Q_UNUSED(std_out);
+			Q_UNUSED(std_in);
+			Q_UNUSED(std_err);
+		}
+
+		// do the actual exec
+		const QString error=execute_process(path, cwd, args);
+		static_assert(std::is_trivially_copyable<QChar>::value,"Can't copy string of QChar to shared memory");
+		std::memcpy(sharedMem,error.constData(),std::min(sizeof(QChar)*error.size(),sharedMemSize-sizeof(QChar)/*prevent overwriting of last null*/));
+
+		// we should never get here!
+		abort();
+		break;
+	}
+	case -1:
+		// error! for some reason we couldn't fork
+		reset();
+		return QObject::tr("Failed to fork");
+	default:
+		// parent
+		do {
+			reset();
+
+			int status;
+			const auto wpidRet=native::waitpid(pid, &status, __WALL);
+			const QString childError(sharedMem);
+			::munmap(sharedMem,sharedMemSize);
+
+			if(wpidRet == -1)
+				return QObject::tr("waitpid() failed: %1").arg(std::strerror(errno))+(childError.isEmpty()?"":QObject::tr(".\nError returned by child:\n%1.").arg(childError));
+
+			if(WIFEXITED(status))
+				return QObject::tr("The child unexpectedly exited with code %1. Error returned by child:\n%2").arg(WEXITSTATUS(status)).arg(childError);
+			if(WIFSIGNALED(status))
+				return QObject::tr("The child was unexpectedly killed by signal %1. Error returned by child:\n%2").arg(WTERMSIG(status)).arg(childError);
+
+			// This happens when exec failed, but just in case it's something another return some description.
+			if(WIFSTOPPED(status) && WSTOPSIG(status) == SIGABRT)
+				return childError.isEmpty() ? QObject::tr("The child unexpectedly aborted") : childError;
+
+			// the very first event should be a STOP of type SIGTRAP
+			if(!WIFSTOPPED(status) || WSTOPSIG(status) != SIGTRAP) {
+				end_debug_session();
+				return QObject::tr("First event after waitpid() should be a STOP of type SIGTRAP, but wasn't, instead status=0x%1")
+											.arg(status,0,16)+(childError.isEmpty()?"":QObject::tr(".\nError returned by child:\n%1.").arg(childError));
+			}
+
+			// create the process
+			process_ = new PlatformProcess(this, pid);
+
+			pid_            = pid;
+
+			detectDebuggeeBitness();
+
+			return statusOK;
+		} while(0);
+		break;
+	}
+}
+
+
+//------------------------------------------------------------------------------
+// Name: last_means_of_capture
+// Desc: Returns how the last process was captured to debug
+//------------------------------------------------------------------------------
+DebuggerCore::MeansOfCapture DebuggerCore::last_means_of_capture() {
+	return lastMeansOfCapture;
+}
+
+//------------------------------------------------------------------------------
+// Name: reset
+// Desc:
+//------------------------------------------------------------------------------
+void DebuggerCore::reset() {
+	threads_.clear();
+	pid_           = 0;
+}
+
+//------------------------------------------------------------------------------
+// Name: create_state
+// Desc:
+//------------------------------------------------------------------------------
+IState *DebuggerCore::create_state() const {
+	return new PlatformState;
+}
+
+//------------------------------------------------------------------------------
+// Name: enumerate_processes
+// Desc:
+//------------------------------------------------------------------------------
+QMap<edb::pid_t, IProcess::pointer> DebuggerCore::enumerate_processes() const {
+	QMap<edb::pid_t, IProcess::pointer> ret;
+
+	int err;
+	::kinfo_proc2 *result;
+	int mib[6];
+	size_t length = 0;
+
+	mib[0] = CTL_KERN;
+	mib[1] = KERN_PROC2;
+	mib[2] = KERN_PROC_ALL;
+	mib[3] = 0;
+	mib[4] = sizeof(struct kinfo_proc2);
+retry:
+	mib[5] = 0;
+
+	err = sysctl(mib, __arraycount(mib), NULL, &length, NULL, 0);
+	if (err == -1)
+		return ret;
+
+	result = (::kinfo_proc2 *)malloc(length);
+	if (result == NULL)
+		return ret;
+
+	mib[5] = length / sizeof(struct kinfo_proc2);
+        err = sysctl(mib, __arraycount(mib), result, &length, NULL, 0);
+	if (err == -1) {
+		if (errno == ENOMEM)
+			goto retry;
+
+		free(result);
+		return ret;
+	}
+
+	for (size_t i = 0; i < length / sizeof(kinfo_proc2); i++) {
+		const edb::pid_t pid = result[i].p_pid;
+		ret.insert(pid, std::make_shared<PlatformProcess>(const_cast<DebuggerCore*>(this), pid));
+	}
+
+	free(result);
+
+	return ret;
+}
+
+
+//------------------------------------------------------------------------------
+// Name:
+// Desc:
+//------------------------------------------------------------------------------
+edb::pid_t DebuggerCore::parent_pid(edb::pid_t pid) const {
+
+	struct user_stat user_stat;
+	int n = get_user_stat(pid, &user_stat);
+	if(n >= 4) {
+		return user_stat.ppid;
+	}
+
+	return 0;
+}
+
+//------------------------------------------------------------------------------
+// Name:
+// Desc: Returns EDB's native CPU type
+//------------------------------------------------------------------------------
+quint64 DebuggerCore::cpu_type() const {
+	if(EDB_IS_32_BIT)
+		return edb::string_hash("x86");
+	else
+		return edb::string_hash("x86-64");
+}
+
+
+//------------------------------------------------------------------------------
+// Name:
+// Desc:
+//------------------------------------------------------------------------------
+QString DebuggerCore::format_pointer(edb::address_t address) const {
+	return address.toPointerString();
+}
+
+//------------------------------------------------------------------------------
+// Name:
+// Desc:
+//------------------------------------------------------------------------------
+QString DebuggerCore::stack_pointer() const {
+	if(edb::v1::debuggeeIs32Bit())
+		return "esp";
+	else
+		return "rsp";
+}
+
+//------------------------------------------------------------------------------
+// Name:
+// Desc:
+//------------------------------------------------------------------------------
+QString DebuggerCore::frame_pointer() const {
+	if(edb::v1::debuggeeIs32Bit())
+		return "ebp";
+	else
+		return "rbp";
+}
+
+//------------------------------------------------------------------------------
+// Name:
+// Desc:
+//------------------------------------------------------------------------------
+QString DebuggerCore::instruction_pointer() const {
+	if(edb::v1::debuggeeIs32Bit())
+		return "eip";
+	else
+		return "rip";
+}
+
+//------------------------------------------------------------------------------
+// Name: flag_register
+// Desc: Returns the name of the flag register as a QString.
+//------------------------------------------------------------------------------
+QString DebuggerCore::flag_register() const {
+	if(edb::v1::debuggeeIs32Bit())
+		return "eflags";
+	else
+		return "rflags";
+}
+
+//------------------------------------------------------------------------------
+// Name: process
+// Desc:
+//------------------------------------------------------------------------------
+IProcess *DebuggerCore::process() const {
+	return process_;
+}
+
+#if QT_VERSION < 0x050000
+Q_EXPORT_PLUGIN2(DebuggerCore, DebuggerCore)
+#endif
+
+}
