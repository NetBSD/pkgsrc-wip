# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/10 10:31:32 bubuchka Exp $

BUILDLINK_TREE+=	RBiocGenerics

.if !defined(RBIOCGENERICS_BUILDLINK3_MK)
RBIOCGENERICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.RBiocGenerics+=	R-BiocGenerics>=0.2.0
BUILDLINK_ABI_DEPENDS.RBiocGenerics+=	R-BiocGenerics>=0.2.0
BUILDLINK_PKGSRCDIR.RBiocGenerics?=	../../wip/R-BiocGenerics
.endif # RBIOCGENERICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-RBiocGenerics
