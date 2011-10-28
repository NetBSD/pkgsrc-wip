# $NetBSD: Makefile,v 1.1.1.1 2011/10/28 17:08:35 jihbed Exp $
#

DISTNAME=	herwig6510
PKGNAME=	herwig-6.510
CATEGORIES=	physics
MASTER_SITES=	http://hepwww.rl.ac.uk/theory/seymour/herwig/
EXTRACT_SUFX=	.f

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://hepwww.rl.ac.uk/theory/seymour/herwig/
COMMENT= Monte Carlo package for simulating Hadron Emission Reactions

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/herwig6510.f

NO_BUILD= yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA} ${WRKDIR}/herwig6510.f ${DESTDIR}${PREFIX}/lib/herwig6510.f

.include "../../mk/bsd.pkg.mk"
