# $NetBSD: Makefile,v 1.2 2012/10/07 16:23:18 asau Exp $
#

DISTNAME=	superchicv1.3
PKGNAME=	superchic-1.3
CATEGORIES=	physics
MASTER_SITES=	http://projects.hepforge.org/superchic/
EXTRACT_SUFX=	.f

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/superchic/
COMMENT=	Monte Carlo Event Generator for Central Exclusive Production

WRKSRC=		${WRKDIR}

NO_BUILD= yes
USE_LANGUAGES=	fortran

INSTALLATION_DIRS= lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/superchicv1.3.f ${DESTDIR}${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
