# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	cinnamon-control-center-3.8.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	cinnamon-control-center
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cinnamon-control-center
COMMENT=	Cinnamon control-center
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config automake intltool msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-networkmanager \
			--disable-onlineaccounts \
			--disable-modemmanager	 \
			--disable-wacom # needs libgudev

PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/menus

CONF_FILES=	share/examples/menus/cinnamoncc.menu \
		${PKG_SYSCONFDIR}/menus/cinnamoncc.menu

BUILD_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive
BUILD_DEPENDS+=	gettext-m4>=0.14.6:../../devel/gettext-m4
TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

#DEPENDS+=	cheese-[0-9]*:../../graphics/cheese

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../security/mate-polkit/buildlink3.mk"
#.include "../../net/gnome-online-accounts/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/colord/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../wip/cinnamon-desktop/buildlink3.mk"
.include "../../wip/cjs/buildlink3.mk"
.include "../../wip/cinnamon-menus/buildlink3.mk"
.include "../../wip/cinnamon-settings-daemon/buildlink3.mk"
.include "../../wip/xapps/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
