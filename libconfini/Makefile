# $NetBSD$

DISTNAME=	libconfini-1.16.3-with-configure
PKGNAME=	${DISTNAME:S/-with-configure//g}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=madmurphy/}
GITHUB_PROJECT=	libconfini
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://madmurphy.github.io/libconfini/
COMMENT=	Yet another INI parser
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/libconfini.pc.in

.include "../../mk/bsd.pkg.mk"
