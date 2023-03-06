# $NetBSD$

DISTNAME=	jack-example-tools-4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=jackaudio/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://jackaudio.org/
COMMENT=	JACK example clients and tools
LICENSE=	gnu-gpl-v2

CONFLICTS=	jack<=1.9.21

.include "../../wip/jack-example-tools/options.mk"

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

.include "../../audio/jack/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
