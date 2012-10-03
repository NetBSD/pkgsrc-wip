# $NetBSD: Makefile,v 1.3 2012/10/03 14:59:11 othyro Exp $
#

PKGVERSION=	1.8.0.1138
DISTNAME=	vbam-${PKGVERSION}-src
PKGNAME=	vba-m-${PKGVERSION}
CATEGORIES=	emulators
MASTER_SITES=	http://sourceforge.net/projects/vbam/files/VBA-M%20svn%20r1138/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vba-m.com/
COMMENT=	VBA-M is a fork from the now inactive VisualBoy Advance project
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DVERSION=${PKGVERSION}
CMAKE_ARGS+=	-DENABLE_WX=OFF # "wx is not even beta state at present"
CMAKE_ARGS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR}
CMAKE_ARGS+=	-DSFML_INCLUDE_DIR=${BUILDLINK_PREFIX.sfml+}/include/SFML
CMAKE_ARGS+=	-DSFML_LIBRARY=${BUILDLINK_PREFIX.sfml+}/lib/libsfml-system.so
EGDIR=		${PREFIX}/share/examples/vbam
CONF_FILES+=	${EGDIR}/vbam.cfg ${PKG_SYSCONFDIR}/vbam.cfg
CMAKE_ARGS+=	-DENABLE_LINK=OFF # broken - needs shm_open() and shm_unlink()

.include "options.mk"

CMAKE_ARGS+=	-DENABLE_FFMPEG=OFF # needs ffmpeg > 0.8
#.include "../../multimedia/ffmpeg/buildlink3.mk"
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
