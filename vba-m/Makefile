# $NetBSD: Makefile,v 1.9 2014/08/11 23:10:14 thomasklausner Exp $

VERSION=	1159
DISTNAME=	vbam-r${VERSION}-src
PKGNAME=	vba-m-1.8.0.${VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vbam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vba-m.com/
COMMENT=	VBA-M is a fork from the now inactive VisualBoy Advance project
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DVERSION=${VERSION}
CMAKE_ARGS+=	-DENABLE_WX=OFF # "wx is not even beta state at present"
CMAKE_ARGS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR}
CMAKE_ARGS+=	-DSFML_LIBRARY=${BUILDLINK_PREFIX.sfml}/lib/libsfml-system.so
EGDIR=		${PREFIX}/share/examples/vbam
CONF_FILES+=	${EGDIR}/vbam.cfg ${PKG_SYSCONFDIR}/vbam.cfg

.include "options.mk"

.if $(OPSYS) == "NetBSD" || $(OPSYS) == "SunOS"
CMAKE_ARGS+=	-DENABLE_LINK=OFF # needs shm_open() and shm_unlink()
.endif

BUILDLINK_DEPMETHOD.glibmm=	build
.include "../../devel/glibmm/buildlink3.mk"
BUILDLINK_DEPMETHOD.gtkmm=	build
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
#.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/sfml/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
