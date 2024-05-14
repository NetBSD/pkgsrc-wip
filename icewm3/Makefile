# $NetBSD$

DISTNAME=	icewm-3.4.7
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=ice-wm/icewm/releases/download/3.4.7/}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ice-wm/icewm/releases/download/3.4.7/
COMMENT=	Small, fast and light-weight window manager
LICENSE=	gnu-gpl-v2

CONFLICTS+=	icewm-imlib-[0-9]*

FILESDIR=	${.CURDIR}/../../wm/icewm/files

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-corefonts
CONFIGURE_ARGS+=	--enable-i18n

USE_TOOLS+=	pkg-config gmake perl

REPLACE_PERL=	contrib/icewm-menu-xrandr

LDFLAGS.SunOS+=	-lsocket -lnsl

post-extract:
	cp ${FILESDIR}/bsd-daemon.xpm ${WRKSRC}/lib/taskbar

.include "../../converters/fribidi/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
