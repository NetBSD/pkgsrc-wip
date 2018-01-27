# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/07/16 17:34:02 jihbed Exp $

BUILDLINK_TREE+=	libowl-av

.if !defined(LIBOWL_AV_BUILDLINK3_MK)
LIBOWL_AV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libowl-av+=	libowl-av>=0.1
BUILDLINK_PKGSRCDIR.libowl-av?=		../../wip/libowl-av

.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"

.endif	# LIBOWL_AV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libowl-av
