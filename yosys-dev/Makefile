# $NetBSD: Makefile,v 1.12 2024/10/22 11:29:50 thorpej Exp $

YOSYS_VERSION=	0.49
GITHUB_PROJECT=	yosys
DISTNAME=	yosys
PKGNAME=	${DISTNAME}-${YOSYS_VERSION}
CATEGORIES=	devel cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_RELEASE=	v${YOSYS_VERSION}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/yosys
COMMENT=	Yosys Open SYnthesis Suite
LICENSE=	isc

DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

ONLY_FOR_COMPILER=	clang gcc
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
GCC_REQD+=		10

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

WRKSRC=	${WRKDIR}

.if ${CC_VERSION:Mclang*}
YOSYS_COMPILER=	clang
.else
YOSYS_COMPILER=	gcc
.endif

USE_TOOLS+=	bash
USE_TOOLS+=	git
USE_TOOLS+=	gmake
USE_TOOLS+=	bison
USE_TOOLS+=	flex
USE_TOOLS+=	gawk
USE_TOOLS+=	pkg-config

REPLACE_PYTHON+=	backends/smt2/*.py
REPLACE_PYTHON+=	docs/source/*.py
REPLACE_PYTHON+=	passes/pmgen/*.py
REPLACE_PYTHON+=	techlibs/common/*.py
REPLACE_PYTHON+=	techlibs/gatemate/*.py
REPLACE_PYTHON+=	techlibs/gowin/*.py
REPLACE_PYTHON+=	techlibs/lattice/*.py
REPLACE_PYTHON+=	techlibs/nexus/*.py
REPLACE_PYTHON+=	techlibs/xilinx/*.py
REPLACE_PYTHON+=	tests/bram/*.py
REPLACE_PYTHON+=	tests/fsm/*.py
REPLACE_PYTHON+=	tests/opt_share/*.py
REPLACE_PYTHON+=	tests/realmath/*.py
REPLACE_PYTHON+=	tests/share/*.py
REPLACE_PYTHON+=	tests/tools/*.py

REPLACE_BASH+=		misc/yosys-config.in
DEPENDS+=		bash-[0-9]*:../../shells/bash

do-configure:
	cd ${WRKSRC} && ${MAKE_PROGRAM} config-${YOSYS_COMPILER}

.include "../../wip/abc/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/cxxopts/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
