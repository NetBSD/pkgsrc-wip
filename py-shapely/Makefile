# $NetBSD: Makefile,v 1.1.1.1 2012/01/24 11:03:52 jihbed Exp $
#

DISTNAME=	Shapely-1.2.14
PKGNAME=	${PYPKGPREFIX}-shapely-1.2.14
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/S/Shapely/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/sgillies/shapely
COMMENT=	Geometric objects, predicates, and operations
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 27 26 25

WRKSRC=	${WRKDIR}/Shapely-1.2.14

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
