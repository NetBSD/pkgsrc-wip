# $NetBSD$

DISTNAME=	reactive-platform-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reactive-platform/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.reactiveexchange.com/
COMMENT=	Reactive Platform Python API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-reactive-papi>=1.2.0:../../wip/py-reactive-papi

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
