# $NetBSD$

PKGNAME=	qfusion-${GIT_REVISION}
GIT_REPO=	https://github.com/Qfusion/qfusion.git
GIT_REVISION=	abd44fe98b9f7223c2070188b8aa56ea6f106d73
CATEGORIES=	games

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://qfusion.github.io/qfusion/
COMMENT=	Game engine derived from id Tech 2
LICENSE=	XXX

WRKSRC=		${WRKDIR}/qfusion/source
USE_LANGUAGES+=	c c++
USE_CMAKE=	yes

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../wip/angelscript/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
