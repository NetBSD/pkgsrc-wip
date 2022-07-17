# $NetBSD$

DISTNAME=	xidle-26052015
CATEGORIES=	x11
MASTER_SITES=	http://distcache.freebsd.org/local-distfiles/novel/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	http://distcache.freebsd.org/local-distfiles/novel/
COMMENT=	Run a program on X inactivity
LICENSE=	isc

MAKEFLAGS+=	X11BASE=${X11BASE}
MAKEFLAGS+=	MANDIR=${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xidle ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xidle.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
