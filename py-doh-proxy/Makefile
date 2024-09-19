# $NetBSD$

DISTNAME=	doh-proxy-0.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebookexperimental/}
GITHUB_PROJECT=	doh-proxy
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebookexperimental/doh-proxy
COMMENT=	Client and proxy implementation of DoH (DNS over HTTPS)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-aioh2>=0.2.1:../../wip/py-aioh2
DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
