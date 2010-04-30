# $NetBSD: Makefile,v 1.1.1.1 2010/04/30 10:13:46 thomasklausner Exp $
#

DISTNAME=	gnome-user-share-2.26.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-user-share/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Easy user-level file sharing
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool pkg-config # msgfmt
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALL_MAKE_FLAGS+=	autostartdir=${PREFIX}/share/applications

#Do note Apache 2.2 and mod_dnssd 0.6 are required to use gnome-user-share.
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
#.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
