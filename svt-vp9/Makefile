# $NetBSD$

GITHUB_PROJECT=	SVT-VP9
GITHUB_TAG=	v0.3.0
DISTNAME=	v0.3.0
PKGNAME=	${GITHUB_PROJECT:tl}-${DISTNAME:S,^v,,}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenVisualCloud/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenVisualCloud/SVT-VP9/
COMMENT=	VP9 encoder
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/SVT-VP9-0.3.0/
USE_CMAKE=	yes

.include "../../mk/bsd.pkg.mk"
