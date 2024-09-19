# $NetBSD$

DISTNAME=	milksnake-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/milksnake/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/getsentry/milksnake/
COMMENT=	Library that extends setuptools for binary extensions
LICENSE=	apache-2.0


DEPENDS+=	${PYPKGPREFIX}-cffi>=1.6.0:../../devel/py-cffi

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
