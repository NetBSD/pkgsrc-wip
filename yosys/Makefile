# $NetBSD$

DISTNAME=	yosys-a44cc7a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cliffordwolf/}
GITHUB_TAG= 	69468d5a16f87616af9c7f084f6ff247f3513050

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cliffordwolf/
COMMENT=	Yosys is a framework for Verilog RTL synthesis
LICENSE=	isc

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config bison
#PYTHON_VERSIONS_ACCEPTED= 36 35 34
PYTHON_VERSIONS_INCOMPATIBLE= 	27
PKGCONFIG_CONFIG= 	${PKG_CONFIG:Q}

WRKSRC= 		${WRKDIR}/yosys-${GITHUB_TAG}

SUBST_CLASSES+= 	python
SUBST_MESSAGE.python= 	Fixing non-shellbang references to python3.
SUBST_STAGE.python= 	pre-configure
SUBST_SED.python= 	-e 's,python3,${PYTHONBIN},g'
SUBST_FILES.python= 	techlibs/common/cellhelp.py \
		techlibs/common/Makefile.inc techlibs/ice40/brams_init.py \
		techlibs/ice40/Makefile.inc techlibs/xilinx/brams_init.py \
		techlibs/xilinx/Makefile.inc tests/bram/generate.py tests/bram/run-test.sh \
		tests/fsm/generate.py tests/fsm/run-test.sh tests/realmath/generate.py \
		tests/realmath/run-test.sh tests/share/generate.py tests/share/run-test.sh \
		tests/tools/txt2tikztiming.py

.include "../../mk/readline.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
