# $NetBSD: Makefile,v 1.4 2012/11/14 03:45:04 othyro Exp $
#

DISTNAME=	superchicv1.3
PKGNAME=	${DISTNAME:S/v/-/1}
CATEGORIES=	misc
MASTER_SITES=	http://projects.hepforge.org/superchic/
EXTRACT_SUFX=	.f

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/superchic/
COMMENT=	Monte Carlo Event Generator for Central Exclusive Production

WRKSRC=		${WRKDIR}

NO_BUILD=	yes
USE_LANGUAGES=	fortran

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/superchicv1.3.f ${DESTDIR}${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
