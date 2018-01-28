# $NetBSD$

DISTNAME=	fs-uae-2.8.0u3
CATEGORIES=	emulators
#MASTER_SITES=	https://fs-uae.net/fs-uae/devel/${PKGVERSION_NOREV}/
MASTER_SITES=	https://fs-uae.net/stable/${PKGVERSION_NOREV}/

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	https://fs-uae.net/
COMMENT=	FS-UAE Amiga Emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config zip
GNU_CONFIGURE=		yes

#CONFIGURE_ARGS +=	--enable-lua
# patchelf is sometimes used, for something with steam or so?
#BUILD_DEPENDS +=	patchelf-*:../../devel/patchelf

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.endif

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
