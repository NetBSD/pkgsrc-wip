# $NetBSD: buildlink3.mk,v 1.1 2014/10/07 14:27:45 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.blast?=	build

BUILDLINK_TREE+=	blast

.if !defined(BLAST_BUILDLINK3_MK)
BLAST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blast+=	blast>=2.2.29
BUILDLINK_PKGSRCDIR.blast?=	../../wip/ncbi-blast
.endif	# BLAST_BUILDLINK3_MK

BUILDLINK_TREE+=	-blast
