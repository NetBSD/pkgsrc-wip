# $NetBSD: Makefile,v 1.1 2013/09/13 23:32:19 jihbed Exp $

DISTNAME=	helio-1.0.0b1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/h/helio/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/yellowpagesgroup/Helio
COMMENT=Componentised, hierarchical, notification driven Python web framework

WRKSRC=		${WRKDIR}/helio-1.0.0b1

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
.include "../../mk/bsd.pkg.mk"
