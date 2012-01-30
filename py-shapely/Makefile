# $NetBSD: Makefile,v 1.2 2012/01/30 03:10:38 noud4 Exp $
#

DISTNAME=	Shapely-1.2.14
PKGNAME=	${PYPKGPREFIX}-shapely-1.2.14
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/S/Shapely/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/sgillies/shapely
COMMENT=	Geometric objects, predicates, and operations
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes

PYTHON_VERSIONS_ACCEPTED= 27 26 25

WRKSRC=	${WRKDIR}/Shapely-1.2.14

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
