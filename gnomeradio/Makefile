# $NetBSD: Makefile,v 1.8 2012/11/13 20:09:31 othyro Exp $
#

DISTNAME=		gnomeradio-1.6
PKGREVISION=		5
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


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
