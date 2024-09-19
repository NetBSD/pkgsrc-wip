# $NetBSD$

DISTNAME=	cPyparsing-2.4.5.0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cPyparsing/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/evhub/cpyparsing
COMMENT=	Cython implementation of PyParsing for use in Coconut
LICENSE=	apache-2.0

BUILDLINK_DEPENDS.${PYPKGPREFIX}-cython+=	build
BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-cython+=	${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
