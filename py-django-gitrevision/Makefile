# $NetBSD: Makefile,v 1.10 2014/12/31 13:58:27 thomasklausner Exp $

DISTNAME=	django-gitrevision-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-gitrevision/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/klen/django-gitrevision.git
COMMENT=	Django git revision
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-gitpython-[0-9]*:../../devel/py-gitpython

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
