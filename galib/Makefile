# $NetBSD: Makefile,v 1.10 2012/09/29 00:50:33 asau Exp $
#

DISTNAME=	galib245
PKGNAME=	galib-2.4.5
CATEGORIES=	devel
MASTER_SITES=	http://lancet.mit.edu/ga/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lancet.mit.edu/ga/
COMMENT=	GAlib contains a set of C++ genetic algorithm objects


USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

pre-configure:
	cd ${WRKSRC}; 					\
	${CAT} makevars|${SED} -e s,DESTDIR=\/usr\/local,DESTDIR=${LOCALBASE}, > makevars.tmp; \
	${CP} makevars makevars.old; ${CP} makevars.tmp makevars; \
	${CP} makefile Makefile

.include "../../mk/bsd.pkg.mk"
