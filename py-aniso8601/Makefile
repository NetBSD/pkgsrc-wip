# $NetBSD$

DISTNAME=	aniso8601-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aniso8601/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://bitbucket.org/nielsenb/aniso8601
COMMENT=	Library for parsing ISO 8601 strings
LICENSE=	modified-bsd


DEPENDS+=	${PYPKGPREFIX}-setuptools>=18.5:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.6.1:../../time/py-dateutil


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
