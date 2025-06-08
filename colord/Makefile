# $NetBSD$

DISTNAME=	colord-1.4.7
CATEGORIES=	graphics gnome
MASTER_SITES=	https://www.freedesktop.org/software/colord/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/software/colord/
COMMENT=	Device color profile management daemon
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool

PKGCONFIG_OVERRIDE+=	lib/colorhug/colorhug.pc.in
PKGCONFIG_OVERRIDE+=	lib/colord/colord.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
MESON_ARGS+=		-Dgusb=false
MESON_ARGS+=		-Dudev=falsea
.endif
MESON_ARGS+=		-Dsystemd=false
MESON_ARGS+=		-Dbash_completion=false

PKGCONFIG_OVERRIDE+=	lib/colorhug/colorhug.pc.in
PKGCONFIG_OVERRIDE+=	lib/colord/colord.pc.in

TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc
TOOL_DEPENDS+=	docbook-xsl-ns-[0-9]*:../../wip/docbook-xsl-ns

.include "options.mk"


.if ${OPSYS} == "Linux"
.include "../../wip/libgusb/buildlink3.mk"
#.include "../../wip/udev/buildlink3.mk"
.include "../../devel/libgudev/buildlink3.mk"
.endif
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../devel/meson/build.mk"

.include "../../mk/bsd.pkg.mk"
