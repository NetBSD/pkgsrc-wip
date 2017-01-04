# $NetBSD: Makefile,v 1.1 2015/08/19 20:36:32 yhardy Exp $
#

EDUKE_SVN=	5974
EDUKE_DATE=	20161225
DISTNAME=	eduke32_src_${EDUKE_DATE}-${EDUKE_SVN}
PKGNAME=	eduke32-${EDUKE_SVN}
CATEGORIES=	games
MASTER_SITES=	http://dukeworld.duke4.net/eduke32/synthesis/${EDUKE_DATE}-${EDUKE_SVN}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eduke32.com/
COMMENT=	Engine for Duke Nukem 3D
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/eduke32_${EDUKE_DATE}-${EDUKE_SVN}
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake pkg-config

BUILD_DEPENDS=	nasm-[0-9]*:../../devel/nasm

BUILD_MAKE_FLAGS+=	"BASELDFLAGS=${BUILDLINK_LDFLAGS.libexecinfo}"
BUILD_MAKE_FLAGS+=	LTO=0 RELEASE=1 SUBPLATFORM=LINUX USE_LIBVPX=0

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eduke32 ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mapster32 ${DESTDIR}${PREFIX}/bin

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
