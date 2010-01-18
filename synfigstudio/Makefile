# $NetBSD: Makefile,v 1.5 2010/01/18 09:38:33 thomasklausner Exp $
#

DISTNAME=	synfigstudio-0.61.08
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=synfig/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://synfig.org/
COMMENT=	Animation studio for 2D animation renderer

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=			GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=			gmake

GCONF2_SCHEMAS+=	synfigstudio-thumbnailer.schemas

USE_TOOLS+=	automake
pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../devel/ETL/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../wip/synfig/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
