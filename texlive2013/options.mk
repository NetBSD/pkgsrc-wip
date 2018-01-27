# $NetBSD: options.mk,v 1.1 2013/11/02 13:01:38 makoto Exp $
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.texlive
PKG_SUPPORTED_OPTIONS=	bundle-lib
# deleting bundle-lib results unable to define FT_Library
PKG_SUGGESTED_OPTIONS=	bundle-lib

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mbundle-lib)
CONFIGURE_ARGS+=	--with-system-cairo
#ONFIGURE_ARGS+=	--with-system-freetype
#ONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ARGS+=	--with-system-gd
CONFIGURE_ARGS+=	--with-system-graphite2
CONFIGURE_ARGS+=	--with-system-harfbuzz
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-kpathsea
#ONFIGURE_ARGS+=	--with-system-libgs
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-pixman
CONFIGURE_ARGS+=	--with-system-poppler
CONFIGURE_ARGS+=	--with-system-ptexenc
CONFIGURE_ARGS+=	--with-system-t1lib
#ONFIGURE_ARGS+=	--with-system-teckit
#ONFIGURE_ARGS+=	--with-system-xpdf
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-system-zziplib

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
#include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/ptexenc/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.else
CONFLICTS=      kpathsea-[0-9]*
.endif
