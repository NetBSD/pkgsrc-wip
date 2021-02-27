# $NetBSD$

GITHUB_PROJECT=	tg_owt
GITHUB_TAG=	10b988aa9111fd25358443ac34d0d422b5108029
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-git
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=desktop-app/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/desktop-app/tg_owt/
COMMENT=	WebRTC build for Telegram
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/tg_owt-${GITHUB_TAG}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

CMAKE_ARGS+= -DCMAKE_C_FLAGS="${CMAKE_C_FLAGS} -fPIC -no-pie"

.include "../../audio/libopus/buildlink3.mk"
.include "../../comms/srtp/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../wip/usrsctp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
