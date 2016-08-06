# $NetBSD: buildlink3.mk,v 1.8 2012/05/07 01:53:52 dholland Exp $

BUILDLINK_TREE+=	daq

.if !defined(DAQ_BUILDLINK3_MK)
DAQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.daq+=	daq>=2.0.0
BUILDLINK_ABI_DEPENDS.daq+=	daq>=2.0.0
BUILDLINK_PKGSRCDIR.daq?=	../../wip/daq
.endif # DAQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-daq
