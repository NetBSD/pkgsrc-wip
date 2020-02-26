# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.17.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libopenshot-audio?=	build

BUILDLINK_TREE+=	libopenshot-audio

.if !defined(LIBOPENSHOT_AUDIO_BUILDLINK3_MK)
LIBOPENSHOT_AUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopenshot-audio+=	libopenshot-audio>=v0.1.8
BUILDLINK_PKGSRCDIR.libopenshot-audio?=	../../wip/libopenshot-audio

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../audio/alsa-lib/buildlink3.mk"
#.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../x11/libXrandr/buildlink3.mk"
#.include "../../x11/libXinerama/buildlink3.mk"
#.include "../../x11/libXcursor/buildlink3.mk"
.endif	# LIBOPENSHOT_AUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopenshot-audio
