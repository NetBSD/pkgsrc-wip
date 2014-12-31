# $NetBSD: Makefile,v 1.2 2014/12/31 13:58:41 thomasklausner Exp $

DISTNAME=	requests-oauthlib-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	https://pypi.python.org/packages/source/r/requests-oauthlib/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/requests/requests-oauthlib
COMMENT=	OAuthlib authentication support for Requests
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-oauthlib>=0.6.1:../../wip/py-oauthlib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
