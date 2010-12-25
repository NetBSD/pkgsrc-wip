# $NetBSD: Makefile,v 1.5 2010/12/25 12:45:45 noud4 Exp $

DISTNAME=	showmesh-1.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www-dinma.univ.trieste.it/nirftc/research/easymesh/
DISTFILES=	showmesh_1_0.c

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www-dinma.univ.trieste.it/nirftc/research/easymesh/
COMMENT=	Display program for easymesh

PKG_DESTDIR_SUPPORT=	user-destdir

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
