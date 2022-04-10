# $NetBSD: buildlink3.mk,v 1.2 2018/04/29 21:00:04 adam Exp $

BUILDLINK_TREE+=	ncbi-blast+

.if !defined(NCBI_BLAST+_BUILDLINK3_MK)
NCBI_BLAST+_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncbi-blast++=	ncbi-blast+>=2.13.0
BUILDLINK_PKGSRCDIR.ncbi-blast+?=	../../wip/ncbi-blast+

.endif	# NCBI_BLAST+_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-blast+
