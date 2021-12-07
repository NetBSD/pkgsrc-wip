# $NetBSD$

DISTNAME=	gnome-boxes-41.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-boxes/41/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gnome-boxes
COMMENT=	View, access, and manage remote and virtual systems
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c

USE_TOOLS+=		pkg-config itstool

MAKE_ENV+=		LD_LIBRARY_PATH=${WKRSRC}/output/subprojects/libovf-glib/govf
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/gnome-boxes

pre-configure:
	cd ${WRKSRC} && meson subprojects download

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../wip/libgudev/buildlink3.mk"
.include "../../devel/libhandy1/buildlink3.mk"
.include "../../wip/spice-gtk/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../sysutils/gnome-tracker/buildlink3.mk"
.include "../../wip/libvirt-glib/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../wip/libosinfo/buildlink3.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../net/gtk-vnc/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
