# $NetBSD: Makefile,v 1.2 2003/06/07 16:06:40 cjep Exp $
#

DISTNAME=       galib245
PKGNAME=	galib-2.4.5
CATEGORIES=     devel
MASTER_SITES=   http://lancet.mit.edu/ga/dist/

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://lancet.mit.edu/ga/
COMMENT=        GAlib contains a set of C++ genetic algorithm objects

USE_BUILDLINK2=         YES
USE_GMAKE=              YES

pre-configure:
	cd ${WRKSRC}; 					\
	${CAT} makevars|${SED} -e s,DESTDIR=\/usr\/local,DESTDIR=${LOCALBASE}, > makevars.tmp; \
	${CP} makevars makevars.old; ${CP} makevars.tmp makevars; \
	${CP} makefile Makefile

.include "../../mk/bsd.pkg.mk"
