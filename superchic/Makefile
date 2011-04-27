# $NetBSD: Makefile,v 1.1.1.1 2011/04/27 22:27:07 jihbed Exp $
#

DISTNAME=	superchicv1.3
PKGNAME=	superchic-1.3
CATEGORIES=	physics
MASTER_SITES=	http://projects.hepforge.org/superchic/
EXTRACT_SUFX=	.f

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/superchic/
COMMENT=	Monte Carlo Event Generator for Central Exclusive Production

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

NO_BUILD= yes
USE_LANGUAGES=	fortran

INSTALLATION_DIRS= lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/superchicv1.3.f ${DESTDIR}${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
