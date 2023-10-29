# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.19.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.

BUILDLINK_TREE+=	portaudio

.if !defined(PORTAUDIO_BUILDLINK3_MK)
PORTAUDIO_BUILDLINK3_MK:=

# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.portaudio?=	build

BUILDLINK_API_DEPENDS.portaudio+=	portaudio>=19.7.0
BUILDLINK_PKGSRCDIR.portaudio?=		../../wip/portaudio
.endif	# PORTAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-portaudio
