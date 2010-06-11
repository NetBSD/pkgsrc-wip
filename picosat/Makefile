# $NetBSD: Makefile,v 1.1.1.1 2010/06/11 11:45:49 jihbed Exp $
#

DISTNAME=	picosat-913
CATEGORIES=	math
MASTER_SITES=	http://fmv.jku.at/picosat/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://fmv.jku.at/picosat/
COMMENT=	SAT solver with proof and core support
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_LANGUAGES= c

MAKE_FILE=		makefile

INCLUDIR=	${PREFIX}/include/picosat

INSTALLATION_DIRS=	bin ${INCLUDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picosat ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/picosat.h ${DESTDIR}${INCLUDIR}

.include "../../mk/bsd.pkg.mk"
