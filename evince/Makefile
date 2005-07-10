# $NetBSD: Makefile,v 1.2 2005/07/10 12:01:07 leonardschmidt Exp $
#

DISTNAME=		evince-0.3.2
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/evince/0.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnome.org/projects/evince/
COMMENT=		Document viewer for multiple formats like PDF and Postscript

#BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_MSGFMT_PLURALS=	YES
USE_PKGLOCALEDIR=	yes

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

#  --disable-schemas-install     Disable the schemas installation
#  --enable-tiff           Compile with support of multipage tiff
#  --enable-djvu           Compile with support of djvu viewer
CONFIGURE_ARGS+=	 --enable-dvi
#  --enable-t1lib          Compile with support of t1lib for type1 fonts in dvi

#GCONF2_SCHEMAS+=	evince-thumbnailer-djvu.schemas
GCONF2_SCHEMAS=		evince-thumbnailer.schemas
GCONF2_SCHEMAS+=	evince-thumbnailer-dvi.schemas
GCONF2_SCHEMAS+=	evince.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/teTeX-bin/kpathsea.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
