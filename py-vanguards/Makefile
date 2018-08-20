# $NetBSD$

DISTNAME=	vanguards-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mikeperry-tor/}
GITHUB_PROJECT=	vanguards
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mikeperry-tor/vanguards/
COMMENT=	Vanguards Onion Service Addon
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-stem-[0-9]*:../../wip/py-stem

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
