# $NetBSD: Makefile,v 1.6 2014/01/17 15:58:20 jihbed Exp $

DISTNAME=	Shapely-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/S/Shapely/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/sgillies/shapely
COMMENT=	Geometric objects, predicates, and operations
LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/Shapely-1.3.0

INSTALLATION_DIRS=	share/doc/py-shapely

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/manual.txt ${DESTDIR}${PREFIX}/share/doc/py-shapely

.include "../../geography/geos/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
