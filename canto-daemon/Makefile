# $NetBSD$

GITHUB_PROJECT=	canto-next
DISTNAME=	${GITHUB_PROJECT}-0.9.7
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=themoken/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/themoken/canto-next/
COMMENT=	The next generation Canto RSS daemon
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/canto-next-0.9.7
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-feedparser<6.0.0:../../textproc/py-feedparser5

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYDISTUTILSPKG=			YES

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
