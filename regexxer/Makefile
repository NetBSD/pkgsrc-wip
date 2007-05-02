# $NetBSD: Makefile,v 1.17 2007/05/02 02:45:44 dhowland Exp $
#

DISTNAME=	regexxer-0.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regexxer/}

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://regexxer.sourceforge.net/
COMMENT=	Interactive tool for performing search and replace operations

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl intltool pkg-config

LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:M*:Q}

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
GCONF2_SCHEMAS=		regexxer.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
