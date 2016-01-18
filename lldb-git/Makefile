# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	lldb-3.9.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	lldb
GIT_REPO.lldb=		git://github.com/llvm-mirror/lldb.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lldb.org/
COMMENT=	next generation, high-performance debugger
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}
CONFIGURE_DIRS=			${WRKDIR}/build

USE_LANGUAGES=		c c++
USE_CMAKE+=		yes
GCC_REQD+=		4.8

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

PY_PATCHPLIST=		yes

REPLACE_PERL+=		${WRKDIR}/lldb/packages/Python/lldbsuite/test/attic/dotest.pl
REPLACE_PERL+=		${WRKDIR}/lldb/scripts/build-llvm.pl
REPLACE_PERL+=		${WRKDIR}/lldb/scripts/checkpoint-llvm.pl
REPLACE_PERL+=		${WRKDIR}/lldb/scripts/disasm-gdb-remote.pl
REPLACE_PERL+=		${WRKDIR}/lldb/scripts/generate-vers.pl
REPLACE_PERL+=		${WRKDIR}/lldb/scripts/sed-sources

REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/darwin/heap_find/heap.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/cmdtemplate.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/crashlog.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/delta.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/disasm-stress-test.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/disasm.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/gdbremote.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/globals.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/lldb_module_utils.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/lldbtk.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/mach_o.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/memory.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/operating_system.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/performance.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/process_events.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/sbvalue.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/sources.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/stacks.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/symbolication.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/types.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/x86_64_linux_target_definition.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/x86_64_qemu_target_definition.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/examples/python/x86_64_target_definition.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/packages/Python/lldbsuite/test/attic/tester.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/packages/Python/lldbsuite/test/bench.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/packages/Python/lldbsuite/test/curses_results.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/packages/Python/lldbsuite/test/dosep.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/packages/Python/lldbsuite/test/functionalities/plugins/python_os_plugin/operating_system.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/packages/Python/lldbsuite/test/functionalities/plugins/python_os_plugin/operating_system2.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/packages/Python/lldbsuite/test/redo.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/packages/Python/lldbsuite/test/test_runner/test/inferior.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/packages/Python/lldbsuite/test/test_runner/test/process_control_tests.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/scripts/Python/remote-build.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/scripts/buildbot.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/scripts/shush
REPLACE_PYTHON+=	${WRKDIR}/lldb/scripts/verify_api.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/scripts/prepare_bindings.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/test/dotest.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/FSM.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/astat.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/bd_client.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/bd_serv.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/cgishell.cgi
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/chess.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/chess2.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/chess3.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/df.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/fix_cvs_files.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/ftp.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/hive.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/monitor.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/passmass.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/python.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/rippy.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/script.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/ssh_tunnel.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/sshls.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/topip.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/pexpect-2.4/examples/uptime.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/third_party/Python/module/progress/progress.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/git-svn/convert.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/lui/lui.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/lui/sandbox.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/misc/grep-svn-log.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/sync-source/syncsource.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/test/disasm.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/test/lldb-disasm.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/test/llvm-mc-shell.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/test/ras.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/test/run-dis.py
REPLACE_PYTHON+=	${WRKDIR}/lldb/utils/test/run-until-faulted.py

TEST_TARGET=		check-lldb
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/build/lib

.if exists(/usr/include/panel.h)
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=FALSE
.else
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=TRUE
.endif

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++

# Try to optimize building LLVM for now.
CMAKE_ARGS+=	-DLLVM_TARGETS_TO_BUILD="X86"

CMAKE_ARG_PATH=	${WRKDIR}/lldb

post-extract:
	${RUN} mkdir -p ${WRKSRC}/build

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/llvm-git/buildlink3.mk"
.include "../../wip/clang-git/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
