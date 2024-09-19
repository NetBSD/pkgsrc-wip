# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:17 othyro Exp $
#

DISTNAME=	pythia-6.4.25.f
PKGNAME=	${DISTNAME:S/.f//1}
CATEGORIES=	misc
MASTER_SITES=	http://www.hepforge.org/archive/pythia6/
EXTRACT_SUFX=	.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.hepforge.org/archive/pythia6/
COMMENT=	Program can be used to generate high-energy-physics events

NO_BUILD=	yes
USE_LANGUAGES=	fortran77

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${WRKDIR}/pythia-6.4.25.f ${DESTDIR}${PREFIX}/include/pythia-6.4.25.f

.include "../../mk/bsd.pkg.mk"
