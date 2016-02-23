# $NetBSD$

DISTNAME=	whichcraft-0.1.1
GITHUB_PROJECT=	whichcraft
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pydanny/}
EXTRACT_SUFX=	.zip

MAINTAINER=	gde@llew.me
HOMEPAGE=	${MASTER_SITE_GITHUB:=pydanny/whichcraft/}
COMMENT=	Cross-platform cross-python shutil.which functionality
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wheel>=0.23.0:../../wip/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
