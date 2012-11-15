# $NetBSD: buildlink3.mk,v 1.1 2012/11/15 22:58:44 bubuchka Exp $

BUILDLINK_TREE+=	Rbigmemory.sri

.if !defined(RBIGMEMORY.SRI_BUILDLINK3_MK)
RBIGMEMORY.SRI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Rbigmemory.sri+=	R-bigmemory.sri>=0.1.2
BUILDLINK_ABI_DEPENDS.Rbigmemory.sri+=	R-bigmemory.sri>=0.1.2
BUILDLINK_PKGSRCDIR.Rbigmemory.sri?=	../../wip/R-bigmemory.sri
.endif # RBIGMEMORY.SRI_BUILDLINK3_MK

BUILDLINK_TREE+=	-Rbigmemory.sri
