# $NetBSD: Makefile,v 1.1.1.1 2009/07/14 19:26:50 tnn2 Exp $
#

DISTNAME=	VirtualBox-3.0.2-OSE
PKGNAME=	virtualbox-3.0.2
CATEGORIES=	emulators
MASTER_SITES=	http://download.virtualbox.org/virtualbox/3.0.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.virtualbox.org/
COMMENT=	general-purpose full virtualizer for x86 hardware
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/VirtualBox-3.0.2_OSE

CHECK_PORTABILITY_SKIP+= src/VBox/VMM/testcase/mkdsk.sh # XXX

BUILD_DEPENDS+=	bcc-[0-9]*:../../devel/bcc
BUILD_DEPENDS+=	kBuild-[0-9]*:../../wip/kBuild
BUILD_DEPENDS+=	acpica-utils-[0-9]*:../../sysutils/acpica-utils
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm

CONFIGURE_ARGS+=	--with-iasl=${PREFIX}/bin/acpi-iasl
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX}
CONFIGURE_ENV+=		ZLIBPREFIX=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ENV+=		MESAPREFIX=${BUILDLINK_PREFIX.MesaLib}

# Major XXX here
CONFIGURE_ARGS+=	--disable-xpcom
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-hardening

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} KBUILD_PATH=${WRKSRC}/kBuild sh -c ". ./env.sh; kmk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
