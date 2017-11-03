# $NetBSD$

BUILDLINK_TREE+=	cutadapt

.if !defined(CUTADAPT_BUILDLINK3_MK)
CUTADAPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cutadapt+=	cutadapt>=1.8.3
BUILDLINK_PKGSRCDIR.cutadapt?=	../../wip/py-cutadapt
.endif	# CUTADAPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-cutadapt
