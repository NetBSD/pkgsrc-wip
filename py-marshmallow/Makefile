# $NetBSD$

DISTNAME=	marshmallow-3.0.0b8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=m/marshmallow/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/marshmallow-code/marshmallow
COMMENT=	Library for converting complex datatypes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.6.1:../../time/py-dateutil

PYTHON_VERSIONS_INCOMPATIBLE=	27

WRKSRC=		${WRKDIR}/marshmallow-3.0.0b8
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
