# $NetBSD$

DISTNAME=	residualvm-0.4.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=residualvm/}
CATEGORIES=	games
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://residualvm.org/
COMMENT=	Lucas Arts' LUA-based 3D adventure engine
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND isc AND ofl-v1.1 AND zlib

GIT_REPOSITORIES=	residualvm
GIT_REPO.residualvm=	git://github.com/residualvm/residualvm.git
WRKSRC=			${WRKDIR}/residualvm

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-all-engines

.include "options.mk"

CONFIGURE_ARGS+=	--disable-nasm

.include "../../devel/SDL2/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
