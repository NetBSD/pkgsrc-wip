# $NetBSD: Makefile,v 1.129 2020/08/26 10:28:39 wiz Exp $
PLIST_SRC=      ${.CURDIR}/../../x11/modular-xorg-server/PLIST

PATCHDIR=       ${.CURDIR}/../../x11/modular-xorg-server/patches
DISTINFO_FILE=  ${.CURDIR}/../../x11/modular-xorg-server/distinfo

DISTNAME=	xorg-server-${XORG_VERSION}
PKGNAME=	modular-${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modular X11 server from modular X.org

SPECIAL_PERMS+=		bin/Xorg ${SETUID_ROOT_PERMS}

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../x11/modular-xorg-server/Makefile.common"

CONFIGURE_ARGS+=	--enable-xorg
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-xwayland
CONFIGURE_ARGS+=	--disable-kdrive
CONFIGURE_ARGS+=	--enable-udev

.include "../../x11/modular-xorg-server/options.mk"

.include "../../wip/libudev/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
