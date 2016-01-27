# $NetBSD$

BUILDLINK_TREE+=	clutter-gst

.if !defined(CLUTTER_GST_BUILDLINK3_MK)
CLUTTER_GST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-gst+=	clutter-gst>=3.0.14
BUILDLINK_PKGSRCDIR.clutter-gst?=	../../wip/clutter-gst

.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/cogl/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-clutter-gst
