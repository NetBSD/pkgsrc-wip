# $NetBSD: buildlink3.mk,v 1.2 2014/10/08 12:44:35 fhajny Exp $

BUILDLINK_TREE+=	blast

.if !defined(BLAST_BUILDLINK3_MK)
BLAST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blast+=	blast>=2.2.29
BUILDLINK_PKGSRCDIR.blast?=	../../wip/ncbi-blast
.endif	# BLAST_BUILDLINK3_MK

BUILDLINK_TREE+=	-blast
