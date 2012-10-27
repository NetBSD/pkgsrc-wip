# $NetBSD: Makefile,v 1.2 2012/10/27 16:52:10 noud4 Exp $
#

DISTNAME=	rdflib-django-0.2.dev-201210061248
EGG_NAME=	rdflib_django-0.2.dev_201210061248
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/r/rdflib-django/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/packages/source/r/rdflib-django/
COMMENT=	Store implementation for RDFlib using Django models as its backend
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/egg.mk"
.include "../../wip/py-rdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
