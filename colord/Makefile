# $NetBSD$

DISTNAME=	colord-1.3.5
PKGREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	https://www.freedesktop.org/software/colord/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/software/colord/
COMMENT=	Device color profile management daemon
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool autoconf aclocal automake

PKGCONFIG_OVERRIDE+=	lib/colorhug/colorhug.pc.in
PKGCONFIG_OVERRIDE+=	lib/colord/colord.pc.in

CONFIGURE_ARGS+=	--disable-gusb
CONFIGURE_ARGS+=	--disable-udev
CONFIGURE_ARGS+=	--disable-bash-completion
CONFIGURE_ARGS+=	--disable-systemd-login
CONFIGURE_ARGS+=	--disable-argyllcms-sensor # XXX wip

PKGCONFIG_OVERRIDE+=	lib/colorhug/colorhug.pc.in
PKGCONFIG_OVERRIDE+=	lib/colord/colord.pc.in

CONF_DIR=	${PREFIX}/share/examples/colord
CONF_FILES+=	${CONF_DIR}/org.freedesktop.ColorManager.conf \
		${PKG_SYSCONFDIR}/dbus-1/system-services/org.freedesktop.ColorManager.conf

pre-configure:
	cd ${WRKSRC} && autoreconf

BUILD_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc

.include "options.mk"

.include "../../graphics/lcms2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
