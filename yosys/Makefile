# $NetBSD$

DISTNAME=	yosys-a44cc7a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cliffordwolf/}
GITHUB_TAG=	69468d5a16f87616af9c7f084f6ff247f3513050

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cliffordwolf/
COMMENT=	Yosys is a framework for Verilog RTL synthesis
LICENSE=	isc

USE_LANGUAGES+=			c c++
USE_TOOLS+=			gmake pkg-config bison gawk flex
PYTHON_VERSIONS_ACCEPTED=	37 36 35 34
PKGCONFIG_CONFIG=		${PKG_CONFIG:Q}
DEPENDS+=			py27-mercurial-[0-9]*:../../devel/py-mercurial

WRKSRC=			${WRKDIR}/yosys-${GITHUB_TAG}

SUBST_CLASSES+=		python3
SUBST_MESSAGE.python3=	Fixing non-shellbang references to python3.
SUBST_STAGE.python3=	pre-configure
SUBST_SED.python3=	-e 's,python3,${PYTHONBIN},g'
SUBST_FILES.python3+=	techlibs/common/Makefile.inc
SUBST_FILES.python3+=	techlibs/ice40/Makefile.inc
SUBST_FILES.python3+=	techlibs/xilinx/Makefile.inc
SUBST_FILES.python3+=	tests/bram/run-test.sh
SUBST_FILES.python3+=	tests/fsm/run-test.sh
SUBST_FILES.python3+=	tests/realmath/run-test.sh
SUBST_FILES.python3+=	tests/share/run-test.sh


SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fixing shellbang references to python3.
SUBST_STAGE.python=	pre-configure
SUBST_SED.python=	-e 's,/usr/bin/env\ python3,${PYTHONBIN},g'
SUBST_FILES.python=	backends/smt2/smtbmc.py
SUBST_FILES.python+=	techlibs/common/cellhelp.py
SUBST_FILES.python+=	techlibs/ice40/brams_init.py
SUBST_FILES.python+=	techlibs/xilinx/brams_init.py
SUBST_FILES.python+=	tests/bram/generate.py
SUBST_FILES.python+=	tests/fsm/generate.py
SUBST_FILES.python+=	tests/realmath/generate.py
SUBST_FILES.python+=	tests/share/generate.py
SUBST_FILES.python+=	tests/tools/txt2tikztiming.py

.include "../../lang/python/pyversion.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
