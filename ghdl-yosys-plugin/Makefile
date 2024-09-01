# $NetBSD$

GITHUB_PROJECT=	ghdl-yosys-plugin
GITHUB_TAG=	511412f984d64ed7c46c4bdbd839f4b3c48f6fa5
DISTNAME=	511412f984d64ed7c46c4bdbd839f4b3c48f6fa5
PKGNAME=	${GITHUB_PROJECT}-0.0.0.224
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=ghdl/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ghdl/ghdl-yosys-plugin/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/ghdl-yosys-plugin-511412f984d64ed7c46c4bdbd839f4b3c48f6fa5
USE_LANGUAGES=	c c++

USE_TOOLS+=	yosys-config ghdl gmake

TOOL_DEPENDS=	yosys-[0-9]*:../../devel/yosys
TOOL_DEPENDS=	ghdl-4*:../../cad/ghdl

.include "../../mk/bsd.pkg.mk"
