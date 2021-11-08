# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:58 wiz Exp $

BUILDLINK_TREE+=	gst-plugins1-ugly

.if !defined(GST_PLUGINS1_UGLY_BUILDLINK3_MK)
GST_PLUGINS1_UGLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-ugly+=	gst-plugins1-ugly>=1.18.4
BUILDLINK_PKGSRCDIR.gst-plugins1-ugly?=		../../wip/gst-plugins1-ugly

.include "../../wip/gstreamer1/buildlink3.mk"
.endif # GST_PLUGINS1_UGLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-ugly
