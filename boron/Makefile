# $NetBSD$

DISTNAME=	v2.1.0
PKGNAME=	boron-${DISTNAME:S,^v,,}
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/wickedsmoke/boron/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://urlan.sourceforge.io/boron/
COMMENT=	Scripting language similar to REBOL
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

WRKSRC=		${WRKDIR}/boron
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run gmake

REPLACE_BASH+=	configure
CONFIG_SHELL=	${BASH}
BUILD_TARGET=	boron
INSTALL_TARGET=	install install-dev

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
