# $NetBSD: Makefile,v 1.11 2006/08/01 20:52:01 dhowland Exp $
#

DISTNAME=	regexxer-0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regexxer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://regexxer.sourceforge.net/
COMMENT=	Interactive tool for performing search and replace operations

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

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
