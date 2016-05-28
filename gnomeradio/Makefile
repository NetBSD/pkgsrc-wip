# $NetBSD: Makefile,v 1.10 2012/11/25 23:32:17 othyro Exp $
#

DISTNAME=		gnomeradio-1.6
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		http://www.wh-hms.uni-ulm.de/~mfcn/gnomeradio/packages/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.wh-hms.uni-ulm.de/~mfcn/gnomeradio/
COMMENT=		FM-radio tuner for the GNOME desktop


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
