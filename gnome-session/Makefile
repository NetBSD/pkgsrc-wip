# $NetBSD: Makefile,v 1.166 2015/10/10 01:58:22 ryoon Exp $
#

DISTNAME=		gnome-session-3.36.0
PKGREVISION=		1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-session/3.36/}
#SITES.gnome-splash-2.16.0.png=	${MASTER_SITE_LOCAL:=gnome-splash/}
EXTRACT_SUFX=		.tar.xz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} #gnome-splash-2.16.0.png

LICENSE=		gnu-gpl-v2
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		GNOME3 session management utilities

BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

#CONFLICTS+=		gnome-core<1.4.2nb4

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gettext-tools perl pkg-config

.include "../../graphics/MesaLib/features.mk"

PLIST_VARS+=		gles2
.if ${MESALIB_SUPPORTS_GLESv2} == "no"
MESON_ARGS+=		-Dgles2=false
.else
PLIST.gles2=		yes
.endif

MESON_ARGS+=		-Dsystemd=false
MESON_ARGS+=		-Dsystemd_session=disable
MESON_ARGS+=		-Dsystemd_journal=false
MESON_ARGS+=		-Dconsolekit=true

MAKE_ENV+=		REAL_GCONFTOOL=${GCONFTOOL2:Q}

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""
CPPFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

# XXX unsure what is needed here instead
GCONF_SCHEMAS=		gnome-session.schemas

#post-extract:
#	${MV} ${WRKSRC}/data/gnome-splash.png \
#	    ${WRKSRC}/data/gnome-splash-orig.png
#	${CP} ${DISTDIR}/gnome-splash-2.16.0.png \
#	    ${WRKSRC}/data/gnome-splash.png

#post-install:
#	${INSTALL_DATA} ${WRKSRC}/data/gnome-splash-orig.png \
#	    ${DESTDIR}${PREFIX}/share/pixmaps/splash/gnome-splash-orig.png


.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../security/policykit-gnome/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.76
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/gnome-settings-daemon/buildlink3.mk"
#.include "../../x11/gnome-control-center/buildlink3.mk"
#.include "../../x11/gnome-desktop/buildlink3.mk"
BUILDLINK_DEPMETHOD.libxslt?=  build
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
