# $NetBSD$

DISTNAME=	libzrtp
PKGNAME=	${DISTNAME}-0.7.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=traviscross/}
GITHUB_TAG=	4cb5110147d2bb7e0466eec8ec838d8372ef54c9
EXTRACT_SUFX=	.zip

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://github.com/traviscross/libzrtp/
COMMENT=	ZRTP Secure VoIP Protocol
LICENSE=	gnu-agpl-v3

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake pkg-config gmake
USE_LANGUAGES=	c c++

post-extract:
	cd ${WRKSRC}; ${MV} configure.in configure.ac
	cd ${WRKSRC}/third_party/bnlib; ${MV} configure.in configure.ac

pre-configure:
	set -x; cd ${WRKSRC}; autoreconf -fiv
	set -x; cd ${WRKSRC}/third_party/bnlib; autoreconf -fiv

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
