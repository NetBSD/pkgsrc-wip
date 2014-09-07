# $NetBSD: buildlink3.mk,v 1.2 2014/09/07 03:33:52 makoto Exp $

BUILDLINK_TREE+=        uhd

.if !defined(UHD_BUILDLINK3_MK)
UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhd+=    uhd>=2.22
BUILDLINK_PKGSRCDIR.uhd?=              ../../wip/uhd
.endif # UHD_BUILDLINK3_MK

BUILDLINK_TREE+=        -uhd
