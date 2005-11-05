# $NetBSD: Makefile,v 1.2 2005/11/05 17:24:09 gschwarz Exp $

DISTNAME=	easymesh-1.4
CATEGORIES=	graphics
MASTER_SITES=	http://www-dinma.univ.trieste.it/nirftc/research/easymesh/
DISTFILES=	easymesh_1_4.c

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www-dinma.univ.trieste.it/nirftc/research/easymesh/
COMMENT=	Mesh generator

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-extract:
		${CP} ${DISTDIR}/easymesh_1_4.c ${WRKSRC}
do-build:
		cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} easymesh_1_4.c -o easymesh ${LDFLAGS} -lm

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/easymesh ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
