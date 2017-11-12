# $NetBSD: Makefile,v 1.2 2015/02/19 18:01:20 jihbed Exp $

DISTNAME=	3.0.1
PKGNAME=	cinnamon-settings-daemon-3.0.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/cinnamon-settings-daemon/archive/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cinnamon-settings-daemon
COMMENT=	Settings daemon for Cinnamon
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config automake autoreconf intltool msgfmt

pre-configure:
		cd ${WRKSRC} && ${SH}  ./autogen.sh

BUILD_DEPENDS+=	gnome-common-[0-9]*:../../devel/gnome-common

.include "../../print/cups-base/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include  "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../security/polkit/buildlink3.mk"

.include "../../wip/libgnomekbd/buildlink3.mk"
.include "../../wip/colord/buildlink3.mk"
.include "../../wip/cinnamon-desktop/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
