# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:43 thomasklausner Exp $
#

DISTNAME=	lazr.uri-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://launchpad.net/lazr.uri/trunk/${PKGVERSION_NOREV}/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/lazr.uri
COMMENT=	Library for parsing, manipulating, and generating URIs
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
