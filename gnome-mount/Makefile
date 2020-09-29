# $NetBSD: Makefile,v 1.42 2017/02/12 06:25:59 ryoon Exp $
#

DISTNAME=		gnome-mount-0.8
PKGREVISION=		37
CATEGORIES?=		sysutils mate
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://hal.freedesktop.org/
COMMENT=	Programs for mounting, unmounting and ejecting storage devices

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

GENERATE_PLIST=		cd ${DESTDIR}${LOCALBASE};find * \! -type d;

CONFIGURE_ARGS+=	--disable-nautilus-extension

GCONF_SCHEMAS+=		gnome-mount.schemas

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
post-extract:
	${CP} ${FILESDIR}/gnome-mount.schemas.in.NetBSD ${WRKSRC}/gnome-mount.schemas.in
.endif


.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../wip/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/hal/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.include "../Makefile"
