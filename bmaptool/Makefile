# $NetBSD: Makefile,v 1.9 2025/11/25 07:03:07 wiz Exp $

DISTNAME=	bmaptool-3.9.0
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=yoctoproject/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yoctoproject/bmaptool
COMMENT=	Block map tools
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

CONFLICTS+=	bmap-tools-[0-9]*
SUPERSEDES=	bmap-tools-[0-9]*

# as of 3.9.0
# 4 failed, 10 passed, 8 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
