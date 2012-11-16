# $NetBSD: buildlink3.mk,v 1.2 2012/11/16 00:07:44 bubuchka Exp $

BUILDLINK_TREE+=	RBiocGenerics

.if !defined(RBIOCGENERICS_BUILDLINK3_MK)
RBIOCGENERICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.RBiocGenerics+=	R-BiocGenerics>=0.4.0
BUILDLINK_ABI_DEPENDS.RBiocGenerics+=	R-BiocGenerics>=0.4.0
BUILDLINK_PKGSRCDIR.RBiocGenerics?=	../../wip/R-BiocGenerics
.endif # RBIOCGENERICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-RBiocGenerics
