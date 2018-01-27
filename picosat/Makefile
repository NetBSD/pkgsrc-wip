# $NetBSD: Makefile,v 1.3 2013/09/21 15:51:50 jihbed Exp $

DISTNAME=	picosat-957
CATEGORIES=	math
MASTER_SITES=	http://fmv.jku.at/picosat/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://fmv.jku.at/picosat/
COMMENT=	SAT solver with proof and core support
LICENSE=	mit

HAS_CONFIGURE=	yes
MAKE_FILE=	makefile

INCLUDIR=	${PREFIX}/include/picosat

INSTALLATION_DIRS=	bin ${INCLUDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picosat ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/picogcnf ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/picomcs ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/picomus ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/picosat.h ${DESTDIR}${INCLUDIR}



.include "../../mk/bsd.pkg.mk"
