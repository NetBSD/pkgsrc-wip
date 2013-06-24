# $NetBSD: Makefile,v 1.9 2013/06/24 09:38:15 noud4 Exp $
#

DISTNAME=	tracker-0.8.18
PKGNAME=	meta-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/tracker/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/tracker/
COMMENT=	Extract information and metadata about your personal data
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool pkg-config
USE_TOOLS+=		msgfmt
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKGCONFIG_OVERRIDE+=	data/tracker-sparql.pc.in
PKGCONFIG_OVERRIDE+=	data/tracker-miner.pc.in
PKGCONFIG_OVERRIDE+=	data/tracker-client.pc.in
PKGCONFIG_OVERRIDE+=	data/tracker-extract.pc.in

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
