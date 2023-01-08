# $NetBSD$

BUILDLINK_TREE+=	avidemux

.if !defined(AVIDEMUX_BUILDLINK3_MK)
AVIDEMUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avidemux+=	avidemux>=2.8.1
BUILDLINK_ABI_DEPENDS.avidemux+=	avidemux>=2.8.1
BUILDLINK_PKGSRCDIR.avidemux?=		../../wip/avidemux

# XXX Add unversioned .so files to buildlink directory to
# avoir build errors with wip/avidemux-plugins.
.if ${SHLIB_TYPE} != "dylib"
BUILDLINK_TARGETS+=		buildlink-avidemux-libadm6-so

FFMPEG_VERSIONED_LIBRARIES=	libADM6avcodec.so
FFMPEG_VERSIONED_LIBRARIES+=	libADM6avformat.so
FFMPEG_VERSIONED_LIBRARIES+=	libADM6avutil.so
FFMPEG_VERSIONED_LIBRARIES+=	libADM6postproc.so
FFMPEG_VERSIONED_LIBRARIES+=	libADM6swscale.so

.PHONY: buildlink-avidemux-libadm6-so
buildlink-avidemux-libadm6-so:
.for library in ${FFMPEG_VERSIONED_LIBRARIES}
	${LN} -s ${PREFIX}/lib/${library} ${BUILDLINK_DIR}/lib/${library}
.endfor
.endif

.endif # AVIDEMUX_BUILDLINK3_MK

BUILDLINK_TREE+=	-avidemux
