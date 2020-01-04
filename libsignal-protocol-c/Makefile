# $NetBSD$

GITHUB_PROJECT=	libsignal-protocol-c
GITHUB_TAG=	v2.3.2
DISTNAME=	v2.3.2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=signalapp/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/signalapp/libsignal-protocol-c/
COMMENT=	Signal Protocol C Library
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/libsignal-protocol-c-2.3.2
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/libsignal-protocol-c.pc.in

.include "../../mk/bsd.pkg.mk"
