# $NetBSD: Makefile,v 1.18 2012/12/09 21:27:53 othyro Exp $
#

DISTNAME=		zapping-0.9.6
PKGREVISION=		5
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zapping/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://zapping.sourceforge.net/Zapping/
COMMENT=		TV viewer for the Gnome desktop


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++ fortran
USE_TOOLS+=		gmake intltool perl

CONFIGURE_ARGS+=	--disable-rebuild-man
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/

GCONF_SCHEMAS+=	zapping.schemas


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
# not used with bktr(4)
#.include "../../wip/rte/buildlink3.mk"
.include "../../wip/zvbi/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
