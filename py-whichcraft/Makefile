# $NetBSD$

GITHUB_PROJECT=	whichcraft
DISTNAME=	0.1.1
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pydanny/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gde@llew.me
HOMEPAGE=	${MASTER_SITE_GITHUB:=pydanny/whichcraft/}
COMMENT=	Cross-platform cross-python shutil.which functionality
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wheel>=0.23.0:../../wip/py-wheel

USE_LANGUAGES=	# none

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

.include "../../lang/python/extension.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
