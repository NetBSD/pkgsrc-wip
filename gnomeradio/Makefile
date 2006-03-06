# $NetBSD: Makefile,v 1.1.1.1 2006/03/06 01:04:59 poppnk Exp $
#

DISTNAME=		gnomeradio-1.6
CATEGORIES=		wip audio
MASTER_SITES=		http://www.wh-hms.uni-ulm.de/~mfcn/gnomeradio/packages/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.wh-hms.uni-ulm.de/~mfcn/gnomeradio/packages/
COMMENT=		FM-radio tuner for the GNOME desktop

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	gnomeradio.schemas
GCONF2_SCHEMAS+=	gnomeradio.schemas

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
