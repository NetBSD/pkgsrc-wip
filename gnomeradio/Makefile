# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:05 thomasklausner Exp $
#

DISTNAME=		gnomeradio-1.6
PKGREVISION=		4
CATEGORIES=		wip audio
MASTER_SITES=		http://www.wh-hms.uni-ulm.de/~mfcn/gnomeradio/packages/

MAINTAINER=		pancake@phreaker.net
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

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
