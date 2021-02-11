# $NetBSD$

DISTNAME=	pydoctor-20.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydoctor/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/twisted/pydoctor
COMMENT=	Python API document generator
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=  27

DEPENDS+=	${PYPKGPREFIX}-astor>=0.8.1:../../devel/py-astor
DEPENDS+=	${PYPKGPREFIX}-cachecontrol-[0-9]*:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.12.2:../../devel/py-lockfile
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
