# $NetBSD$

BUILDLINK_TREE+=	py-cutadapt

.if !defined(CUTADAPT_BUILDLINK3_MK)
CUTADAPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cutadapt+=	py-cutadapt>=1.14
BUILDLINK_PKGSRCDIR.cutadapt?=	../../wip/py-cutadapt
.endif	# CUTADAPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cutadapt
