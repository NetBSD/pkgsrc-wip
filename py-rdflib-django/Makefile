# $NetBSD: Makefile,v 1.4 2015/04/13 23:22:03 othyro Exp $

DISTNAME=	rdflib-django-0.2.dev-201210061248
EGG_NAME=	rdflib_django-0.2.dev201210061248
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rdflib-django/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/r/rdflib-django/
COMMENT=	Store implementation for RDFlib using Django models as its backend
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-rdflib-[0-9]*:../../textproc/py-rdflib

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.2.dev-201210061248

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
