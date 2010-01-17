# $NetBSD: Makefile,v 1.5 2010/01/17 12:03:33 thomasklausner Exp $
#

DISTNAME=	VirtualBox-${VBOX_VER}-OSE
PKGNAME=	virtualbox-${VBOX_VER}
VBOX_VER=	3.0.4
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${VBOX_VER}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.virtualbox.org/
COMMENT=	general-purpose full virtualizer for x86 hardware
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/VirtualBox-${VBOX_VER}_OSE

CHECK_PORTABILITY_SKIP+= src/VBox/VMM/testcase/mkdsk.sh # XXX

BUILD_DEPENDS+=	dev86-[0-9]*:../../devel/dev86
BUILD_DEPENDS+=	kBuild-[0-9]*:../../wip/kBuild
BUILD_DEPENDS+=	acpica-utils-[0-9]*:../../sysutils/acpica-utils
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm

CONFIGURE_ARGS+=	--with-iasl=${PREFIX}/bin/acpi-iasl
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX}
CONFIGURE_ENV+=		ZLIBPREFIX=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ENV+=		MESAPREFIX=${BUILDLINK_PREFIX.MesaLib}

ALL_ENV+=	VBOX_BLD_PYTHON=${PYTHONBIN}

# Major XXX here
CONFIGURE_ARGS+=	--disable-xpcom
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-hardening
CONFIGURE_ARGS+=	--disable-kmods
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-pulse
CONFIGURE_ARGS+=	--disable-opengl
CONFIGURE_ARGS+=	--disable-qt4
#CONFIGURE_ARGS+=	--with-qt4-dir=${PREFIX}/qt4

post-extract:
	cp -R ${FILESDIR}/src/VBox/Runtime/r3/netbsd ${WRKSRC}/src/VBox/Runtime/r3
	cp -R ${FILESDIR}/src/VBox/HostDrivers/Support/netbsd ${WRKSRC}/src/VBox/HostDrivers/Support

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} KBUILD_PATH=${WRKSRC}/kBuild sh -c ". ./env.sh; kmk"

#.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
#.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
