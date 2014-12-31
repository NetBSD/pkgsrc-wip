# $NetBSD: Makefile,v 1.2 2014/12/31 13:58:27 thomasklausner Exp $

DISTNAME=	django-mathjax-0.0.5
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
