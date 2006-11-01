# $NetBSD: options.mk,v 1.2 2006/11/01 22:22:04 brook1 Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.grass
PKG_SUPPORTED_OPTIONS=	ffmpeg fftw freetype glw gmath motif nls
PKG_SUPPORTED_OPTIONS+=	odbc opengl readline sqlite terraflow
PKG_SUGGESTED_OPTIONS=	ffmpeg fftw freetype glw motif nls
PKG_SUGGESTED_OPTIONS+=	odbc opengl readline sqlite terraflow

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mffmpeg)
CONFIGURE_ARGS+=	--with-ffmpeg
CONFIGURE_ARGS+=	--with-ffmpeg-includes=${LOCALBASE}/include/ffmpeg
.include "../../multimedia/ffmpeg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if !empty(PKG_OPTIONS:Mfftw)
CONFIGURE_ARGS+=	--with-fftw
CONFIGURE_ARGS+=	--with-fftw-includes=${LOCALBASE}/include
PLIST_SRC+=		PLIST.fftw
.include "../../math/fftw2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-fftw
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--with-freetype
PLIST_SRC+=		PLIST.freetype
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.if !empty(PKG_OPTIONS:Mglw)
CONFIGURE_ARGS+=	--with-glw
.else
CONFIGURE_ARGS+=	--without-glw
.endif

.if !empty(PKG_OPTIONS:Mgmath)
USE_LANGUAGES+=		fortran
CONFIGURE_ARGS+=	--with-blas
CONFIGURE_ARGS+=	--with-lapack
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-blas
CONFIGURE_ARGS+=	--without-lapack
.endif

.if !empty(PKG_OPTIONS:Mmotif)
CONFIGURE_ARGS+=	--with-motif
PLIST_SRC+=		PLIST.motif
.include "../../mk/motif.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-motif
.endif

.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+=	--with-nls
PLIST_SRC+=		PLIST.nls
.else
CONFIGURE_ARGS+=	--without-nls
.endif

.if !empty(PKG_OPTIONS:Modbc)
CONFIGURE_ARGS+=	--with-odbc
PLIST_SRC+=		PLIST.odbc
.include "../../databases/unixodbc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-odbc
.endif

.if !empty(PKG_OPTIONS:Mopengl)
CONFIGURE_ARGS+=	--with-opengl
.else
CONFIGURE_ARGS+=	--without-opengl
.endif

.if !empty(PKG_OPTIONS:Mreadline)
CONFIGURE_ARGS+=	--with-readline
.include "../../devel/readline/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite
CONFIGURE_ARGS+=	--with-sqlite
CONFIGURE_ARGS+=	--with-sqlite-includes=${LOCALBASE}/include
.include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

.if !empty(PKG_OPTIONS:Mterraflow)
USE_LANGUAGES+=		c++
CONFIGURE_ARGS+=	--with-cxx
PLIST_SRC+=		PLIST.terraflow
.else
CONFIGURE_ARGS+=	--without-cxx
.endif
