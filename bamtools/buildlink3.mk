# $NetBSD$

BUILDLINK_TREE+=	bamtools

.if !defined(BAMTOOLS_BUILDLINK3_MK)
BAMTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bamtools+=	bamtools>=2.4.0
BUILDLINK_PKGSRCDIR.bamtools?=		../../wip/bamtools
.endif	# BAMTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-bamtools
