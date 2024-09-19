# $NetBSD: buildlink3.mk,v 1.1 2012/09/13 00:31:14 jihbed Exp $

BUILDLINK_TREE+=	argtable2

.if !defined(ARGTABLE2_BUILDLINK3_MK)
ARGTABLE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.argtable2+=	argtable2>=2.13
BUILDLINK_PKGSRCDIR.argtable2?=		../../wip/argtable2
.endif	# ARGTABLE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-argtable2
