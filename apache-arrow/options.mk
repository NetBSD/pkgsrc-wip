# $NetBSD: options.mk,v 1.5 2019/04/26 13:13:46 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.apache-arrow
PKG_SUPPORTED_OPTIONS=	brotli bzip2 google-log json lz4 parquet python snappy zlib zstd
PKG_SUGGESTED_OPTIONS=	brotli bzip2 google-log json lz4 parquet python snappy zlib zstd

.include "../../mk/bsd.options.mk"

# The CMAKE_CONFIGURE_ARGS are for the C++ libraries
# The MAKE_ENV are for the python bindings

.if !empty(PKG_OPTIONS:Mbrotli)
.include "../../archivers/brotli/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_BROTLI=ON
.endif

.if !empty(PKG_OPTIONS:Mbzip2)
.include "../../archivers/bzip2/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_BZ2=ON
.endif

.if !empty(PKG_OPTIONS:Mgoogle-log)
.include "../../devel/google-glog/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DARROW_USE_GLOG=OFF=ON
.endif

.if !empty(PKG_OPTIONS:Mjson)
.include "../../textproc/rapidjson/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DARROW_JSON=ON
.endif

.if !empty(PKG_OPTIONS:Mlz4)
.include "../../archivers/lz4/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_LZ4=ON
.endif

.if !empty(PKG_OPTIONS:Mparquet)
CMAKE_CONFIGURE_ARGS+=	-DARROW_PARQUET=ON
MAKE_ENV+=	PYARROW_WITH_PARQUET=1
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
CMAKE_CONFIGURE_ARGS+=	-DPython3_EXECUTABLE=${PYTHONBIN}
.endif

.if !empty(PKG_OPTIONS:Msnappy)
.include "../../devel/snappy/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_SNAPPY=ON
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_ZLIB=ON
.endif

.if !empty(PKG_OPTIONS:Mzstd)
.include "../../archivers/zstd/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DARROW_WITH_ZSTD=ON
.endif
