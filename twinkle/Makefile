# $NetBSD$

DISTNAME=	twinkle-1.10.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=LubosD/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://twinkle.dolezei.info/
COMMENT=	SIP-based VOIP client
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex

CMAKE_CONFIGURE_ARGS+=	-DWITH_ALSA:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_SPEEX:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_ZRTP:BOOL=ON

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ucommon/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/ccrtp/buildlink3.mk"
.include "../../net/libzrtpcpp/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
