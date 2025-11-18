# $NetBSD$

DISTNAME=	yt_dlp_ejs-0.3.1-py3-none-any
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g:S/-py3-none-any//}}
CATEGORIES=	net python
MASTER_SITES=	https://files.pythonhosted.org/packages/e7/fd/34fbdaf0d53386c47e219c532a479766cd9336fde34c00834c8e0123df7a/
EXTRACT_SUFX=	.whl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yt-dlp/ejs
COMMENT=	External JavaScript for yt-dlp supporting many runtimes
LICENSE=	unlicense AND mit AND isc

DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

USE_LANGUAGES=	# none
USE_TOOLS+=	unzip

do-build:
	cd ${WRKDIR} && unzip ${DISTNAME}.whl

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
