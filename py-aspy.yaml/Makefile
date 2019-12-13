# $NetBSD$

DISTNAME=	aspy.yaml-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aspy.yaml/}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://github.com/asottile/aspy.yaml
COMMENT=	Some extensions to pyyaml
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
