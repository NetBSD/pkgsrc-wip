# $NetBSD$

DISTNAME=	musl-fts-1.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=void-linux/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/void-linux/musl0fts
COMMENT=	Implementation of fts(3) for musl libc
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS=	autoconf automake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	musl-fts.pc.in

pre-configure:
	cd ${WRKSRC} && ${SH} bootstrap.sh

.include "../../mk/bsd.pkg.mk"
