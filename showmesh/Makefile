# $NetBSD: Makefile,v 1.6 2012/10/07 16:23:04 asau Exp $

DISTNAME=	showmesh-1.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://web.archive.org/web/20170109013501/http://www-dinma.univ.trieste.it/nirftc/research/easymesh/
DISTFILES=	showmesh_1_0.c

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20170109013501/http://www-dinma.univ.trieste.it/nirftc/research/easymesh/
COMMENT=	Display program for easymesh

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${DISTDIR}/showmesh_1_0.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} showmesh_1_0.c -o showmesh ${LDFLAGS} -lX11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/showmesh ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
