# $NetBSD: Makefile,v 1.7 2012/09/29 00:50:37 asau Exp $
#

DISTNAME=		gnomeradio-1.6
PKGREVISION=		4
CATEGORIES=		wip audio
MASTER_SITES=		http://www.wh-hms.uni-ulm.de/~mfcn/gnomeradio/packages/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.wh-hms.uni-ulm.de/~mfcn/gnomeradio/
COMMENT=		FM-radio tuner for the GNOME desktop

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF_SCHEMAS+=	gnomeradio.schemas
GCONF_SCHEMAS+=	gnomeradio.schemas

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
