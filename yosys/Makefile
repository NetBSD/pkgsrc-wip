# $NetBSD$

GITHUB_PROJECT=	yosys
GITHUB_TAG=	refs/tags/${DISTNAME}
DISTNAME=	yosys-0.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yosyshq.net/yosys/
COMMENT=	Framework for Verilog RTL synthesis
LICENSE=	isc

USE_LANGUAGES+=			c c++
USE_TOOLS+=			gmake pkg-config bison gawk flex
PYTHON_VERSIONS_INCOMPATIBLE=	27
# PKGCONFIG_CONFIG=		${PKG_CONFIG:Q}

WRKSRC=			${WRKDIR}/yosys-${DISTNAME}

SUBST_CLASSES+=		python3
SUBST_MESSAGE.python3=	Fixing non-shellbang references to python3.
SUBST_STAGE.python3=	pre-configure
SUBST_SED.python3=	-e 's,python3,${PYTHONBIN},g'
SUBST_FILES.python3+=	Makefile
SUBST_FILES.python3+=	techlibs/gowin/Makefile.inc
SUBST_FILES.python3+=	tests/bram/run-test.sh
SUBST_FILES.python3+=	tests/fsm/run-test.sh
SUBST_FILES.python3+=	tests/opt_share/run-test.sh
SUBST_FILES.python3+=	tests/realmath/run-test.sh
SUBST_FILES.python3+=	tests/rpc/exec.ys
SUBST_FILES.python3+=	tests/rpc/run-test.sh
SUBST_FILES.python3+=	tests/share/run-test.sh

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fixing shellbang references to python3.
SUBST_STAGE.python=	pre-configure
SUBST_SED.python=	-e 's,/usr/bin/env python3,${PYTHONBIN},g'
SUBST_FILES.python=	backends/edif/runtest.py
SUBST_FILES.python+=	backends/smt2/smtbmc.py
SUBST_FILES.python+=	passes/pmgen/pmgen.py
SUBST_FILES.python+=	techlibs/common/cellhelp.py
SUBST_FILES.python+=	techlibs/ecp5/brams_connect.py
SUBST_FILES.python+=	techlibs/ecp5/brams_init.py
SUBST_FILES.python+=	techlibs/gowin/brams_init.py
SUBST_FILES.python+=	techlibs/ice40/brams_init.py
SUBST_FILES.python+=	techlibs/nexus/cells_xtra.py
SUBST_FILES.python+=	techlibs/xilinx/brams_init.py
SUBST_FILES.python+=	techlibs/xilinx/cells_xtra.py
SUBST_FILES.python+=	tests/bram/generate.py
SUBST_FILES.python+=	tests/fsm/generate.py
SUBST_FILES.python+=	tests/opt_share/generate.py
SUBST_FILES.python+=	tests/realmath/generate.py
SUBST_FILES.python+=	tests/share/generate.py
SUBST_FILES.python+=	tests/tools/txt2tikztiming.py

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM=	rm:-ldl
.endif

.include "../../lang/python/pyversion.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
