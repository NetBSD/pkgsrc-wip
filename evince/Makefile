# $NetBSD: Makefile,v 1.1.1.1 2005/07/08 20:38:54 jeremy-c-reed Exp $
#

DISTNAME=		evince-0.3.2
CATEGORIES=		print
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/sources/evince/0.3/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnome.org/projects/evince/
COMMENT=		Document viewer for multiple formats like PDF and Postscript

USE_LIBTOOL=		yes
USE_TOOLS=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

#  --disable-schemas-install     Disable the schemas installation
#  --enable-tiff           Compile with support of multipage tiff
#  --enable-djvu           Compile with support of djvu viewer
CONFIGURE_ARGS+=	 --enable-dvi
#  --enable-t1lib          Compile with support of t1lib for type1 fonts in dvi

#GCONF2_SCHEMAS+=	evince-thumbnailer-djvu.schemas
GCONF2_SCHEMAS+=	evince-thumbnailer.schemas
GCONF2_SCHEMAS+=	evince-thumbnailer-dvi.schemas
GCONF2_SCHEMAS+=	evince.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
