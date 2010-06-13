# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:05 thomasklausner Exp $
#

DISTNAME=		gnome-jabber-0.4
PKGREVISION=		3
CATEGORIES=		chat
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/sources/gnome-jabber/0.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ftp.gnome.org/pub/GNOME/sources/gnome-jabber/0.4/
COMMENT=		Instant message client for Gnome using the Jabber protocol.

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

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
