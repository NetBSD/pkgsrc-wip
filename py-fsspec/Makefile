# $NetBSD$

DISTNAME=	fsspec-0.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fsspec/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/intake/filesystem_spec
COMMENT=	TODO: Short description of the package
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
