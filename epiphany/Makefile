# $NetBSD: Makefile,v 1.162 2016/01/06 10:46:50 adam Exp $

DISTNAME=	epiphany-3.16.3
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany/3.16/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/
COMMENT=	The web browser for the GNOME Desktop
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

PKGCONFIG_OVERRIDE=	data/epiphany.pc.in

.include "options.mk"

GCONF_SCHEMAS=		Epiphany.enums.xml
GCONF_SCHEMAS+=		epiphany.gschema.xml

.include "../../wip/gsettings-desktop-schemas/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/gcr/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.18.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=		libxml2>=2.6.12
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
