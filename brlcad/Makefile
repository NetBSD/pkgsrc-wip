# $NetBSD$

DISTNAME=	brlcad-7.24.2
CATEGORIES=	cad
MASTER_SITES=	https://sourceforge.net/projects/brlcad/files/BRL-CAD%20Source/7.24.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://sourceforge.net/projects/brlcad/files/BRL-CAD%20Source/7.24.2/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

HAS_CONFIGURE=	yes
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

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
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libwdb.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libpc.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libbn.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libbu.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libbrlcad.pc.in
PKGCONFIG_OVERRIDE+=	src/other/libpng/scripts/libpng.pc.in
PKGCONFIG_OVERRIDE+=	src/other/libpng/libpng.pc.in
PKGCONFIG_OVERRIDE+=	src/other/libz/zlib.pc.in

.include "../../x11/tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
