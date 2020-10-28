# $NetBSD$

DISTNAME=	zope.security-5.1.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/zope.s/ZopeS/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/storm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/zopefoundation/zope.security
COMMENT=	Zope Security Framework
LICENSE=        zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.proxy>=4.3.5:../../www/py-zope.proxy

PYTHON_VERSIONED_DEPENDENCIES+= setuptools

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
