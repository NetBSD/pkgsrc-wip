# $NetBSD: Makefile,v 1.3 2003/11/22 20:34:36 minskim Exp $
#

DISTNAME=		imhangul_status_applet-0.2
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://download.kldp.net/imhangul/

MAINTAINER=		minskim@bawi.org
HOMEPAGE=		http://imhangul.kldp.net/\#APPLET
COMMENT=		GNOME2 applet to show imhangul status

DEPENDS=		imhangul>=0.9.6:../imhangul

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS=		imhangul_status.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../x11/gnome-panel/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
