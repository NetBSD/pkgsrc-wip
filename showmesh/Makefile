# $NetBSD: Makefile,v 1.1.1.1 2005/07/02 19:08:17 gschwarz Exp $

DISTNAME=	showmesh-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www-dinma.univ.trieste.it/nirftc/research/easymesh/
DISTFILES=	showmesh_1_0.c

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www-dinma.univ.trieste.it/nirftc/research/easymesh/
COMMENT=	a display program for easymesh

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-extract:
		${CP} ${DISTDIR}/showmesh_1_0.c ${WRKSRC}
do-build:
		cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} showmesh_1_0.c -o showmesh ${LDFLAGS} -lX11

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/showmesh ${PREFIX}/bin

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
