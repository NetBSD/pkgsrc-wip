# $NetBSD: Makefile,v 1.7 2013/01/19 14:09:41 thomasklausner Exp $
#

VERSION=	1.8.0.1138
PKGREVISION=	1
DISTNAME=	vbam-${VERSION}-src
PKGNAME=	vba-m-${VERSION}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vbam/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vba-m.com/
COMMENT=	VBA-M is a fork from the now inactive VisualBoy Advance project
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DVERSION=${VERSION}
CMAKE_ARGS+=	-DENABLE_WX=OFF # "wx is not even beta state at present"
CMAKE_ARGS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR}
CMAKE_ARGS+=	-DSFML_INCLUDE_DIR=${BUILDLINK_PREFIX.sfml+}/include/SFML
CMAKE_ARGS+=	-DSFML_LIBRARY=${BUILDLINK_PREFIX.sfml+}/lib/libsfml-system.so
EGDIR=		${PREFIX}/share/examples/vbam
CONF_FILES+=	${EGDIR}/vbam.cfg ${PKG_SYSCONFDIR}/vbam.cfg

.include "options.mk"

.if $(OPSYS) == "NetBSD" || $(OPSYS) == "SunOS"
CMAKE_ARGS+=	-DENABLE_LINK=OFF # needs shm_open() and shm_unlink()
.endif

BUILD_DEPENDS+=	glibmm-[0-9]*:../../devel/glibmm
BUILD_DEPENDS+=	gtkmm-[0-9]*:../../x11/gtkmm
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../wip/sfml+/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
#.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
