# $NetBSD$

DISTNAME=	spice-vdagent-0.19.0
CATEGORIES=	sysutils
MASTER_SITES=	https://www.spice-space.org/download/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://spice-space.org/
COMMENT=	Agent for Spice guests
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

MAKE_DIRS+=	${PKG_SYSCONFBASEDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/autostart/spice-vdagent.desktop \
		${PKG_SYSCONFBASEDIR}/xdg/autostart/spice-vdagent.desktop

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
