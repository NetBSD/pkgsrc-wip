# $NetBSD: Makefile,v 1.1.1.1 2005/07/24 23:48:57 thomasklausner Exp $
#

DISTNAME=		zapping-0.9.6
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zapping/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://zapping.sourceforge.net/
COMMENT=		TV viewer for the Gnome desktop

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-dirs-1.2 gnome-dirs-1.5
USE_TOOLS+=		gmake perl

CONFIGURE_ARGS+=	--disable-rebuild-man
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	zapping.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
# not used with bktr(4)
#.include "../../wip/rte/buildlink3.mk"
.include "../../wip/zvbi/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
