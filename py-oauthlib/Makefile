# $NetBSD: Makefile,v 1.1 2014/03/21 17:34:32 jihbed Exp $

DISTNAME=	oauthlib-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security www python
MASTER_SITES=	https://pypi.python.org/packages/source/o/oauthlib/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/idan/oauthlib
COMMENT=	OAuth request-signing logic
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-crypto>=2.6.1:../../security/py-crypto

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
