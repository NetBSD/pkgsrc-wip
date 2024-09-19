# $NetBSD$

DISTNAME=	zope.security-5.1.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/zope.s/ZopeS/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/storm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/zopefoundation/zope.security
COMMENT=	Zope Security Framework
LICENSE=        zpl-2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-zope.proxy>=4.3.5:../../www/py-zope.proxy

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
