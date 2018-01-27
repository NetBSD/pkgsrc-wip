# $NetBSD: buildlink3.mk,v 1.1 2014/09/05 05:57:23 makoto Exp $

BUILDLINK_TREE+=	uhd

.if !defined(UHD_BUILDLINK3_MK)
UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhd+=	uhd>=2.22
BUILDLINK_PKGSRCDIR.uhd?=	../../wip/uhd-git
.endif # UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhd
