# $NetBSD$

DISTNAME=	pathod-0.15
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitmproxy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pathod.net/
COMMENT=	Pathological HTTP daemon
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flask>=0.10.1:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-netlib>=0.15:../../net/py-netlib
DEPENDS+=	${PYPKGPREFIX}-pip>=1.5.6:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.5:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-requests>=2.8.1:../../devel/py-requests

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-netlib

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
