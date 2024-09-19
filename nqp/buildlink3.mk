# $NetBSD: buildlink3.mk,v 1.5 2015/04/06 08:17:15 adam Exp $

BUILDLINK_TREE+=	nqp

.if !defined(NQP_BUILDLINK3_MK)
NQP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nqp+=		nqp>=2015.11
BUILDLINK_ABI_DEPENDS.nqp+=		nqp>=2015.11
BUILDLINK_PKGSRCDIR.nqp?=		../../lang/nqp

.include "../../devel/MoarVM/buildlink3.mk"
.endif # NQP_BUILDLINK3_MK

BUILDLINK_TREE+=	-nqp
