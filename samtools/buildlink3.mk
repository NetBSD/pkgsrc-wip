# $NetBSD: buildlink3.mk,v 1.1 2014/09/04 21:46:49 outpaddling Exp $

BUILDLINK_TREE+=	samtools

.if !defined(SAMTOOLS_BUILDLINK3_MK)
SAMTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.samtools+=	samtools>=0.1.19
BUILDLINK_PKGSRCDIR.samtools?=	../../jb-wip/samtools
.endif	# SAMTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-samtools
