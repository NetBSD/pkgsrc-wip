# $NetBSD: Makefile,v 1.1 2015/10/07 12:33:16 adam Exp $

DISTNAME=	libepoll-shim-0.0.20161220
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=FreeBSDDesktop/}
GITHUB_PROJECT=	epoll-shim
GITHUB_TAG=	c04b26b

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FreeBSDDesktop/libepoll-shim
COMMENT=	epoll shim implemented using kevent
LICENSE=	mit

USE_LANGUAGES=	c
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/epoll-shim-c04b26bc60b0520e80a41b8ac0165d0ed9ef595b/

MAKE_FLAGS+=	INCSDIR=${PREFIX}/include/libepoll-shim/sys
MAKE_FLAGS+=	LIBDIR=${PREFIX}/lib
MAKE_FLAGS+=	WITHOUT_PROFILE=yes
MAKE_FLAGS+=	MKPROFILE=no

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
BUILDLINK_TRANSFORM+=	opt:-Weverything:-Wall
BUILDLINK_TRANSFORM+=	opt:-Wno-missing-variable-declarations:-Wno-missing-declarations
BUILDLINK_TRANSFORM+=	rm:-Wno-thread-safety-analysis
.endif

INSTALLATION_DIRS=	lib include/libepoll-shim/sys

post-install:
	cp ${WRKSRC}/include/sys/*.h ${DESTDIR}${PREFIX}/include/libepoll-shim/sys

.include "../../mk/bsd.pkg.mk"
