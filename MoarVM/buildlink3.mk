# $NetBSD$

BUILDLINK_TREE+=	MoarVM

.if !defined(MOARVM_BUILDLINK3_MK)
MOARVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.MoarVM+=	MoarVM>=2015.12
BUILDLINK_PKGSRCDIR.MoarVM?=	../../wip/MoarVM

.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
.endif	# MOARVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-MoarVM
