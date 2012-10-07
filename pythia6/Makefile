# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:33 asau Exp $
#

DISTNAME=	pythia-6.4.25.f
PKGNAME=	pythia-6.4.25
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/pythia6/
EXTRACT_SUFX=	.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.hepforge.org/archive/pythia6/
COMMENT=	Program can be used to generate high-energy-physics events

NO_BUILD= yes
USE_LANGUAGES=	fortran77

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${WRKDIR}/pythia-6.4.25.f ${DESTDIR}${PREFIX}/include/pythia-6.4.25.f

.include "../../mk/bsd.pkg.mk"
