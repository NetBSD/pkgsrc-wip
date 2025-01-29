# $NetBSD$

GITHUB_PROJECT=	ghdl-yosys-plugin
GITHUB_TAG=	511412f984d64ed7c46c4bdbd839f4b3c48f6fa5
DISTNAME=	511412f984d64ed7c46c4bdbd839f4b3c48f6fa5
PKGNAME=	${GITHUB_PROJECT}-0.0.0.224
CATEGORIES=	cad devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ghdl/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ghdl/ghdl-yosys-plugin/
COMMENT=	VHDL synthesis plugin based on GHDL and Yosys
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/ghdl-yosys-plugin-511412f984d64ed7c46c4bdbd839f4b3c48f6fa5
USE_LANGUAGES=	c c++

RELRO_SUPPORTED=	no

USE_TOOLS+=	gmake

TOOL_DEPENDS+=	yosys-[0-9]*:../../wip/yosys-dev

DEPENDS+=	ghdl-4.1.*:../../wip/ghdl-dev

.include "../../mk/bsd.pkg.mk"
#
# gcc6-aux dependency is not met on Linux. Hence we use native gnat on Linux
.if ${OPSYS} != "Linux"
DEPENDS+=	gcc10-aux-10.*:../../lang/gcc10-aux
.endif
