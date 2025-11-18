# $NetBSD$

DISTNAME=	yt_dlp_ejs-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yt_dlp_ejs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yt-dlp/ejs
COMMENT=	External JavaScript for yt-dlp supporting many runtimes
LICENSE=	unlicense AND mit AND isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

USE_LANGUAGES=	# none

# should be no
ALLOW_NETWORK_ACCESS=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
