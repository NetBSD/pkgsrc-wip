# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/04 09:07:31 bubuchka Exp $

BUILDLINK_TREE+=	RdoParallel

.if !defined(RDOPARALLEL_BUILDLINK3_MK)
RDOPARALLEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.RdoParallel+=	R-doParallel>=1.0.1
BUILDLINK_ABI_DEPENDS.RdoParallel+=	R-doParallel>=1.0.1
BUILDLINK_PKGSRCDIR.RdoParallel?=	../../wip/R-doParallel
.endif # RDOPARALLEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-RdoParallel
