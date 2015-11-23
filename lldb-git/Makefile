# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $
#
# This is a dummy package - only for lldb/llvm porting efforts
# It will conflict with clang and llvm packages

PKGNAME=	lldb-3.7.0
CATEGORIES=	lang devel

GIT_REPOSITORIES=	llvm lldb clang
GIT_REPO.llvm=		git://github.com/llvm-mirror/llvm.git
GIT_REPO.clang=		git://github.com/llvm-mirror/clang.git
GIT_REPO.lldb=		git://github.com/llvm-mirror/lldb.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lldb.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/build

USE_LANGUAGES=		c c++
USE_CMAKE+=		yes
GCC_REQD+=		4.8

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

PY_PATCHPLIST=		yes

REPLACE_PERL+=		${WRKDIR}/llvm/tools/clang/test/make_test_dirs.pl
REPLACE_PERL+=		${WRKDIR}/llvm/tools/clang/tools/scan-build/bin/scan-build
REPLACE_PERL+=		${WRKDIR}/llvm/tools/clang/tools/scan-build/libexec/c++-analyzer
REPLACE_PERL+=		${WRKDIR}/llvm/tools/clang/tools/scan-build/libexec/ccc-analyzer
REPLACE_PERL+=		${WRKDIR}/llvm/tools/clang/utils/TestUtils/pch-test.pl
REPLACE_PERL+=		${WRKDIR}/llvm/tools/clang/utils/analyzer/reducer.pl
REPLACE_PERL+=		${WRKDIR}/llvm/tools/clang/utils/analyzer/update_plist_test.pl
REPLACE_PERL+=		${WRKDIR}/llvm/tools/clang/www/demo/index.cgi
REPLACE_PERL+=		${WRKDIR}/llvm/tools/lldb/packages/Python/lldbsuite/test/attic/dotest.pl
REPLACE_PERL+=		${WRKDIR}/llvm/tools/lldb/scripts/build-llvm.pl
REPLACE_PERL+=		${WRKDIR}/llvm/tools/lldb/scripts/checkpoint-llvm.pl
REPLACE_PERL+=		${WRKDIR}/llvm/tools/lldb/scripts/disasm-gdb-remote.pl
REPLACE_PERL+=		${WRKDIR}/llvm/tools/lldb/scripts/generate-vers.pl
REPLACE_PERL+=		${WRKDIR}/llvm/tools/lldb/scripts/sed-sources
REPLACE_PERL+=		${WRKDIR}/llvm/utils/GenLibDeps.pl
REPLACE_PERL+=		${WRKDIR}/llvm/utils/UpdateCMakeLists.pl
REPLACE_PERL+=		${WRKDIR}/llvm/utils/codegen-diff
REPLACE_PERL+=		${WRKDIR}/llvm/utils/findsym.pl
REPLACE_PERL+=		${WRKDIR}/llvm/utils/llvm-native-gxx
REPLACE_PERL+=		${WRKDIR}/llvm/utils/test_debuginfo.pl

REPLACE_PYTHON+=	${WRKDIR}/llvm/examples/Kaleidoscope/MCJIT/cached/genk-timing.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/examples/Kaleidoscope/MCJIT/cached/split-lib.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/examples/Kaleidoscope/MCJIT/complete/genk-timing.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/examples/Kaleidoscope/MCJIT/complete/split-lib.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/examples/Kaleidoscope/MCJIT/lazy/genk-timing.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/test/BugPoint/compile-custom.ll.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/test/tools/llvm-readobj/Inputs/relocs.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/bindings/python/examples/cindex/cindex-dump.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/bindings/python/examples/cindex/cindex-includes.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/docs/tools/dump_ast_matchers.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/docs/tools/dump_format_style.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/tools/clang-format/clang-format-diff.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/tools/clang-format/git-clang-format
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/tools/scan-build/bin/set-xcode-analyzer
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/tools/scan-view/bin/scan-view
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/ABITest/ABITestGen.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/CIndex/completion_logger_server.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/CaptureCmd
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/CmpDriver
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/FindSpecRefs
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/FuzzTest
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/TestUtils/deep-stack.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/analyzer/CmpRuns.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/analyzer/SATestAdd.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/analyzer/SATestBuild.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/analyzer/SumTimerInfo.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/analyzer/ubiviz
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/check_cfc/check_cfc.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/check_cfc/obj_diff.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/check_cfc/test_check_cfc.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/utils/token-delta.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/clang/www/builtins.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/darwin/heap_find/heap.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/cmdtemplate.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/crashlog.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/delta.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/disasm-stress-test.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/disasm.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/gdbremote.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/globals.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/lldb_module_utils.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/lldbtk.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/mach_o.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/memory.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/operating_system.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/performance.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/process_events.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/sbvalue.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/sources.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/stacks.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/symbolication.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/types.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/x86_64_linux_target_definition.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/x86_64_qemu_target_definition.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/examples/python/x86_64_target_definition.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/packages/Python/lldbsuite/test/attic/tester.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/packages/Python/lldbsuite/test/bench.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/packages/Python/lldbsuite/test/curses_results.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/packages/Python/lldbsuite/test/dosep.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/packages/Python/lldbsuite/test/functionalities/plugins/python_os_plugin/operating_system.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/packages/Python/lldbsuite/test/functionalities/plugins/python_os_plugin/operating_system2.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/packages/Python/lldbsuite/test/redo.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/packages/Python/lldbsuite/test/test_runner/test/inferior.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/packages/Python/lldbsuite/test/test_runner/test/process_control_tests.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/scripts/Python/remote-build.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/scripts/buildbot.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/scripts/shush
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/scripts/verify_api.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/scripts/prepare_bindings.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/test/dotest.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/FSM.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/astat.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/bd_client.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/bd_serv.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/cgishell.cgi
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/chess.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/chess2.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/chess3.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/df.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/fix_cvs_files.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/ftp.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/hive.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/monitor.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/passmass.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/python.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/rippy.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/script.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/ssh_tunnel.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/sshls.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/topip.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/pexpect-2.4/examples/uptime.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/third_party/Python/module/progress/progress.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/git-svn/convert.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/lui/lui.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/lui/sandbox.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/misc/grep-svn-log.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/sync-source/syncsource.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/test/disasm.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/test/lldb-disasm.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/test/llvm-mc-shell.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/test/ras.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/test/run-dis.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/tools/lldb/utils/test/run-until-faulted.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/Misc/zkill
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/Target/ARM/analyze-match-table.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/bisect
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/clang-parse-diagnostics-file
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/create_ladder_graph.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/git/find-rev
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lint/common_lint.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lint/cpp_lint.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lint/generic_lint.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lit/lit.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lit/lit/ProgressBar.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lit/lit/main.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/lit/tests/Inputs/googletest-format/DummySubDir/OneTest
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/llvm-build/llvm-build
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/llvm-compilers-check
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/llvm-lit/llvm-lit.in
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/release/findRegressions-nightly.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/release/findRegressions-simple.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/schedcover.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/shuffle_fuzz.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/sort_includes.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/testgen/mc-bundling-x86-gen.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/update_llc_test_checks.py
REPLACE_PYTHON+=	${WRKDIR}/llvm/utils/wciia.py

BUILD_TARGET=		lldb lldb-mi

TEST_TARGET=		check-lldb
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/lib

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

CMAKE_ARG_PATH=	${WRKDIR}/llvm

post-extract:
	${RUN} mkdir -p ${WRKSRC}
	${RUN} mv ${WRKDIR}/clang/ ${WRKDIR}/llvm/tools
	${RUN} mv ${WRKDIR}/lldb/ ${WRKDIR}/llvm/tools

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
