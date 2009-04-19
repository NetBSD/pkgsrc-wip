# $NetBSD: Makefile,v 1.4 2009/04/19 20:20:52 gschwarz Exp $

DISTNAME=	easymesh-1.4
CATEGORIES=	graphics
MASTER_SITES=	http://www-dinma.univ.trieste.it/nirftc/research/easymesh/
DISTFILES=	easymesh_1_4.c

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www-dinma.univ.trieste.it/nirftc/research/easymesh/
COMMENT=	Mesh generator

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-extract:
		cp ${DISTDIR}/easymesh_1_4.c ${WRKSRC}
do-build:
		cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} easymesh_1_4.c -o easymesh ${LDFLAGS} -lm

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/easymesh ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
