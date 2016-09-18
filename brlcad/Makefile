# $NetBSD$

DISTNAME=	brlcad-7.26.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=brlcad/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://brlcad.org/
COMMENT=	Cross-platform solid modeling system
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

#CMAKE_ARGS+=	-DBRLCAD_BUNDLED_LIBS=ON

PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libanalyze.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/librt.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libfft.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libfb.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libdm.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libmultispectral.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/liboptical.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libicv.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libpkg.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libgcv.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libged.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libgm.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libwdb.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libpc.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libbn.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libbu.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libbrlcad.pc.in
PKGCONFIG_OVERRIDE+=	src/other/libpng/scripts/libpng.pc.in
PKGCONFIG_OVERRIDE+=	src/other/libpng/libpng.pc.in
PKGCONFIG_OVERRIDE+=	src/other/libz/zlib.pc.in

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
