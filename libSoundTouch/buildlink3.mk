# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libSoundTouch

.if !defined(LIBSOUNDTOUCH_BUILDLINK3_MK)
LIBSOUNDTOUCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libSoundTouch+=	libSoundTouch>=1.3.1
BUILDLINK_PKGSRCDIR.libSoundTouch?=	../../wip/libSoundTouch
BUILDLINK_DEPMETHOD.libSoundTouch?=	build
.endif # LIBSOUNDTOUCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libSoundTouch
