# $NetBSD$

GITHUB_PROJECT=	jack-example-tools
GITHUB_TAG=	refs/tags/3
DISTNAME=	3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=jackaudio/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://jackaudio.org/
COMMENT=	JACK example clients and tools
LICENSE=	gnu-gpl-v2

CONFLICTS=	jack<=1.9.21

.include "../../wip/jack-example-tools/options.mk"

WRKSRC=		${WRKDIR}/jack-example-tools-3
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

.include "../../audio/jack/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
