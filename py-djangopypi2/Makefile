# $NetBSD: Makefile,v 1.5 2014/06/01 12:49:40 thomasklausner Exp $

DISTNAME=	djangopypi2-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangopypi2/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/benliles/djangopypi/
COMMENT=	Django application that emulates the Python Package Index
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.9:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-docutils

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
