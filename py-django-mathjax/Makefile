# $NetBSD: Makefile,v 1.1 2014/10/06 23:06:21 jihbed Exp $

DISTNAME=	django-mathjax-0.0.5
EGG_NAME=	django_mathjax-0.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math www python
MASTER_SITES=	https://pypi.python.org/packages/source/d/django-mathjax/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/kaleidos/django-mathjax
COMMENT=	MathJax easy integration with django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
