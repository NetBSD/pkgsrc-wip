# $NetBSD: Makefile,v 1.4 2010/12/24 18:00:53 noud4 Exp $

DISTNAME=	showmesh-1.0
PKGREVISION=	1
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
.if ${X11_TYPE} == "modular"
.include "../../x11/libX11/buildlink3.mk"
.else
.include "../../mk/x11.buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
