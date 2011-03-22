# $NetBSD: Makefile,v 1.7 2011/03/22 06:10:38 phonohawk Exp $
#

DISTNAME=	synfigstudio-0.62.02
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=synfig/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://synfig.org/
COMMENT=	Animation studio for 2D animation renderer
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=			gmake

GCONF_SCHEMAS+=	synfigstudio-thumbnailer.schemas
post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GCONF_SCHEMAS_DIR}
	${INSTALL_DATA} ${WRKSRC}/synfigstudio-thumbnailer.schemas \
		${DESTDIR}${GCONF_SCHEMAS_DIR}

.include "../../wip/ETL/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../wip/synfig/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
