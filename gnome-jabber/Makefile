# $NetBSD: Makefile,v 1.8 2012/09/29 00:50:36 asau Exp $
#

DISTNAME=		gnome-jabber-0.4
PKGREVISION=		3
CATEGORIES=		chat
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/sources/gnome-jabber/0.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ftp.gnome.org/pub/GNOME/sources/gnome-jabber/0.4/
COMMENT=		Instant message client for Gnome using the Jabber protocol.

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_TOOLS+=		perl

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF_SCHEMAS+=	gnome-jabber.schemas
GCONF_SCHEMAS+=	gnome-jabber.schemas

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
