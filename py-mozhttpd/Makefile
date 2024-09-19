# $NetBSD$

DISTNAME=	mozhttpd-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/11/64/d0a3fc500be3468dced5c2eddd6a5fa1a97dc3c1c6cc3a1e99d472644129/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Python webserver intended for use with Mozilla testing
LICENSE=	mpl-2.0

DEPENDS+=	# ${PYPKGPREFIX}-moznetwork>=0.24
DEPENDS+=	# ${PYPKGPREFIX}-mozinfo>=1.0.0
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
