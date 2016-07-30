# $NetBSD$

GITHUB_PROJECT=	canto-next
DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	canto-daemon-0.9.6
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=themoken/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/themoken/canto-next/
COMMENT=	The next generation Canto RSS daemon
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/canto-next-0.9.6
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYDISTUTILSPKG=			YES

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
