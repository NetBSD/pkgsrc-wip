# $NetBSD: Makefile,v 1.1.1.1 2011/04/23 22:00:55 jihbed Exp $
#

DISTNAME=	pythia-6.4.25.f
PKGNAME=	pythia-6.4.25
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/pythia6/
EXTRACT_SUFX=	.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.hepforge.org/archive/pythia6/
COMMENT=	Program can be used to generate high-energy-physics events

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD= yes
USE_LANGUAGES=	fortran77

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${WRKDIR}/pythia-6.4.25.f ${DESTDIR}${PREFIX}/include/pythia-6.4.25.f

.include "../../mk/bsd.pkg.mk"
