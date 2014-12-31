# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:41 thomasklausner Exp $

DISTNAME=	rdflib-django-0.2.dev-201210061248
EGG_NAME=	rdflib_django-0.2.dev201210061248
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/r/rdflib-django/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/packages/source/r/rdflib-django/
COMMENT=	Store implementation for RDFlib using Django models as its backend
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PYTHON_VERSIONS_INCOMPATIBLE=	26 33 34 # not yet ported as of 0.2.dev-201210061248

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../wip/py-rdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
