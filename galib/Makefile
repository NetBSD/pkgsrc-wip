# $NetBSD: Makefile,v 1.3 2004/01/25 02:12:36 grantbeattie Exp $
#

DISTNAME=       galib245
PKGNAME=	galib-2.4.5
CATEGORIES=     devel
MASTER_SITES=   http://lancet.mit.edu/ga/dist/

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://lancet.mit.edu/ga/
COMMENT=        GAlib contains a set of C++ genetic algorithm objects

USE_BUILDLINK2=         YES
USE_GNU_TOOLS+=		make

pre-configure:
	cd ${WRKSRC}; 					\
	${CAT} makevars|${SED} -e s,DESTDIR=\/usr\/local,DESTDIR=${LOCALBASE}, > makevars.tmp; \
	${CP} makevars makevars.old; ${CP} makevars.tmp makevars; \
	${CP} makefile Makefile

.include "../../mk/bsd.pkg.mk"
