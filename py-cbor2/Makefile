# $NetBSD$

DISTNAME=	cbor2-5.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cbor2/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/cbor2
COMMENT=	Pure Python CBOR (de)serializer with extensive tag support
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.7.0:../../devel/py-setuptools_scm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
