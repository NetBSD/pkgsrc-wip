# $NetBSD$

VERSION=	5.026
DISTNAME=	verilator-${VERSION}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=verilator/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/verilator/verilator/
COMMENT=	Convert HDL (Verilog etc) into a C++ or SystemC model
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	verilator.pc.in

REPLACE_PERL+= \
	bin/verilator

REPLACE_PYTHON= \
	bin/verilator_ccache_report \
#	bin/verilator_difftree \
#	bin/verilator_gantt \
#	bin/verilator_profcfunc

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
