# $NetBSD: options.mk,v 1.8 2014/08/11 23:10:13 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.grass
PKG_SUPPORTED_OPTIONS=	fftw freetype gmath iodbc motif mysql
PKG_SUPPORTED_OPTIONS+=	opengl pgsql python sqlite unixodbc
# PKG_SUPPORTED_OPTIONS+=	ffmpeg		# XXX - handle includes
# PKG_SUPPORTED_OPTIONS+=	glw		# XXX - requires libGLw(M)
# PKG_SUPPORTED_OPTIONS+=	wxWidgets	# XXX - need new version
PKG_SUGGESTED_OPTIONS+=	fftw freetype gmath iodbc motif
PKG_SUGGESTED_OPTIONS+=	opengl pgsql python sqlite

.include "../../mk/bsd.options.mk"

# XXX - requires handling of split header directories:  include/libav*
.if !empty(PKG_OPTIONS:Mffmpeg)
CONFIGURE_ARGS+=	--with-ffmpeg
CONFIGURE_ARGS+=	--with-ffmpeg-includes=${PREFIX}/include/libavcodec
CONFIGURE_ARGS+=	--with-ffmpeg-libs=${PREFIX}/lib
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if !empty(PKG_OPTIONS:Mfftw)
CONFIGURE_ARGS+=	--with-fftw
CONFIGURE_ARGS+=	--with-fftw-includes=${PREFIX}/include
PLIST.fftw=		yes
.include "../../math/fftw2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-fftw
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--with-freetype
PLIST.freetype=		yes
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

# XXX - requires GLw support
.if !empty(PKG_OPTIONS:Mglw)
CONFIGURE_ARGS+=	--with-glw
CONFIGURE_ARGS+=	--with-glw-includes=${PREFIX}/include/GL
CONFIGURE_ARGS+=	--with-glw-libs=${PREFIX}/lib
.include "../../graphics/MesaLib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-glw
.endif

.if !empty(PKG_OPTIONS:Mgmath)
USE_LANGUAGES+=		fortran
CONFIGURE_ARGS+=	--with-blas
CONFIGURE_ARGS+=	--with-blas-libs=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-lapack
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-blas
CONFIGURE_ARGS+=	--without-lapack
.endif

.if !empty(PKG_OPTIONS:Miodbc)
CONFIGURE_ARGS+=	--with-odbc
PLIST.iodbc=		yes
.include "../../databases/iodbc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-odbc
.endif

.if !empty(PKG_OPTIONS:Mmotif)
CONFIGURE_ARGS+=	--with-motif
PLIST.motif=		yes
.include "../../mk/motif.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-motif
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
PLIST.mysql=		yes
.  include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Mopengl)
CONFIGURE_ARGS+=	--with-opengl
PLIST.opengl=		yes
.include "../../graphics/Mesa/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-opengl
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgres
PLIST.pgsql=		yes
.  include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-postgres
.endif

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PREFIX}/bin/python${PYVERSSUFFIX}-config
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite
CONFIGURE_ARGS+=	--with-sqlite
CONFIGURE_ARGS+=	--with-sqlite-includes=${PREFIX}/include
PLIST.sqlite=		yes
.include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

.if !empty(PKG_OPTIONS:Munixodbc)
CONFIGURE_ARGS+=	--with-odbc
PLIST.unixodbc=		yes
.include "../../databases/unixodbc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-odbc
.endif

# XXX - requires new version of wxWidgets
.if !empty(PKG_OPTIONS:MwxWidgets)
CONFIGURE_ARGS+=	--with-wxwidgets=${PREFIX}/bin/wx-config
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-wxWidgets
.include "../../x11/py-wxWidgets/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-wxwidgets
.endif
