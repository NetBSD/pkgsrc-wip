PKG_OPTIONS_VAR=		PKG_OPTIONS.rocksdb
PKG_SUPPORTED_OPTIONS=		jemalloc gflags snappy jni zlib bz2 lz4 zstd rados tests sse42
PKG_OPTIONS_OPTIONAL_GROUPS=	sanitize
PKG_OPTIONS_GROUP.sanitize=	asan tsan ubsan
PKG_SUGGESTED_OPTIONS=		jemalloc gflags tests

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjemalloc)
MAKE_ENV+=	JEMALLOC=1 WITH_JEMALLOC_FLAG=1
.include "../../devel/jemalloc/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgflags)
MAKE_ENV+=	GFLAGS=1
.include "../../devel/gflags/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msnappy)
MAKE_ENV+=	SNAPPY=1
.include "../../devel/snappy/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjni)
MAKE_ENV+=	JNI=1
PKG_JVM_DEFAULT=openjdk8
.include "../../mk/java-vm.mk"
.endif

.if !empty(PKG_OPTIONS:Mzlib)
MAKE_ENV+=	ZLIB=1
.include "../../devel/zlib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mbz2)
MAKE_ENV+=	BZ2=1
.endif

.if !empty(PKG_OPTIONS:Mlz4)
MAKE_ENV+=	LZ4=1
.include "../../archivers/lz4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mzstd)
MAKE_ENV+=	ZSTD=1
.include "../../archivers/zstd/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrados)
MAKE_ENV+=	LIBRADOS=1
.endif

.if empty(PKG_OPTIONS:Mtests)
MAKE_ENV+=	TESTS=0
.endif

.if !empty(PKG_OPTIONS:Msse42)
MAKE_ENV+=	FORCE_SSE42=1
.endif

.if !empty(PKG_OPTIONS:Masan)
MAKE_ENV+=	ASAN=1
.endif

.if !empty(PKG_OPTIONS:Mtsan)
MAKE_ENV+=	TSAN=1
.endif

.if !empty(PKG_OPTIONS:Mubsan)
MAKE_ENV+=	UBSAN=1
.endif

