# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:43 thomasklausner Exp $
#

DISTNAME=	lazr.restfulclient-0.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://launchpad.net/lazr.restfulclient/trunk/${PKGVERSION_NOREV}/+download/

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://launchpad.net/lazr.restfulclient
COMMENT=	Provide added functionality on top of wadllib
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-wadllib-[0-9]*:../../wip/py-wadllib
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-oauthlib-[0-9]*:../../security/py-oauthlib

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
