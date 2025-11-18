# $NetBSD$

DISTNAME=	yt_dlp_ejs-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yt_dlp_ejs/}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/yt_dlp_ejs/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

USE_LANGUAGES=	# none

# should be no
ALLOW_NETWORK_ACCESS=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
