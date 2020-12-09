# $NetBSD$

DISTNAME=	reactive-papi-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reactive-papi/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.reactivemarkets.com/
COMMENT=	Reactive Platform flatbuffer api
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
