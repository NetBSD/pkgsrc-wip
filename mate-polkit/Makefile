# $NetBSD: Makefile,v 1.5 2015/04/09 20:38:31 krytarowski Exp $

DISTNAME=	mate-polkit-1.12.0
CATEGORIES=	security
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE desktop environment Authentication Agent for PolicyKit
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	polkitgtkmate/polkit-gtk-mate-1.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	share/examples/mate-polkit/xdg/autostart/polkit-mate-authentication-agent-1.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/polkit-mate-authentication-agent-1.desktop

.include "options.mk"

.include "../../wip/polkit/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
