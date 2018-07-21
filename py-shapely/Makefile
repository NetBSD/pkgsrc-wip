# $NetBSD: Makefile,v 1.8 2014/06/20 10:40:28 jihbed Exp $

DISTNAME=	Shapely-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Shapely/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/sgillies/shapely
COMMENT=	Geometric objects, predicates, and operations
LICENSE=	2-clause-bsd

INSTALLATION_DIRS=	share/doc/py-shapely
PYTHON_VERSIONS_INCOMPATIBLE= 34 35 36 37

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/manual.txt ${DESTDIR}${PREFIX}/share/doc/py-shapely

.include "../../geography/geos/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
