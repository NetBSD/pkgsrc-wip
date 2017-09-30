# $NetBSD$

DISTNAME=	qiew-1.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mtivadar/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mtivadar/qiew/
COMMENT=	Reverse engineering tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYSETUP=	buildsetup.py

DEPENDS+=	${PYPKGPREFIX}-distorm3-[0-9]*:../../devel/py-distorm3
DEPENDS+=	${PYPKGPREFIX}-cxfreeze-[0-9]*:../../lang/py-cxfreeze

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
