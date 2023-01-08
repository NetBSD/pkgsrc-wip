# $NetBSD$

.include "../../wip/avidemux/Makefile.common"

PKGNAME=	${DISTNAME:S/_/-/}
COMMENT=	Graphical video editing program (Core)

USE_TOOLS+=	gmake perl

CMAKE_ARG_PATH=			${WRKSRC}/avidemux_core
CMAKE_MODULE_PATH_OVERRIDE=	${CMAKE_ARG_PATH}/CMakeLists.txt

# XXX By default, macOS uses a case-insensitive filesystem.
# Then VERSION is included by '#include<version>'.
post-configure:
	${RUN}${RM} -f ${WRKSRC}/${CONFIGURE_DIRS}/ffmpeg/source/VERSION

# XXX wip/avidemux-plugings has build error: -lADM6xxx not found.
# It can be fixed with unversioned .so file.
.if ${SHLIB_TYPE} != "dylib"
FFMPEG_VERSIONED_LIBRARIES=	libADM6avcodec.so.58
FFMPEG_VERSIONED_LIBRARIES+=	libADM6avformat.so.58
FFMPEG_VERSIONED_LIBRARIES+=	libADM6avutil.so.56
FFMPEG_VERSIONED_LIBRARIES+=	libADM6postproc.so.55
FFMPEG_VERSIONED_LIBRARIES+=	libADM6swscale.so.5

post-install:
.for library in ${FFMPEG_VERSIONED_LIBRARIES}
	cd ${DESTDIR}${PREFIX}/lib && \
		${LN} -sf ${library} ${library:R}
.endfor
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
