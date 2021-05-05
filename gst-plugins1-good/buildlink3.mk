# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:58 wiz Exp $

BUILDLINK_TREE+=	gst-plugins1-good

.if !defined(GST_PLUGINS1_GOOD_BUILDLINK3_MK)
GST_PLUGINS1_GOOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-good+=	gst-plugins1-good>=1.18.4
BUILDLINK_PKGSRCDIR.gst-plugins1-good?=		../../wip/gst-plugins1-good

.include "../../wip/gstreamer1/buildlink3.mk"
.endif # GST_PLUGINS1_GOOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-good
