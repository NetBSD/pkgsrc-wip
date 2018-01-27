# $NetBSD: Makefile,v 1.1 2014/07/15 09:36:22 jihbed Exp $

DISTNAME=	chinup-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=c/chinup/}

MAINTAINER=	kamelderouiche@yahoo.com	
HOMEPAGE=	https://github.com/pagepart/chinup
COMMENT=	Python Facebook Graph API client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
