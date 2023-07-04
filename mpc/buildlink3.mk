# $NetBSD: buildlink3.mk,v 1.11 2018/01/28 16:24:11 wiz Exp $

BUILDLINK_TREE+=	mpc

.if !defined(MPC_BUILDLINK3_MK)
MPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpc+=	mpc>=1.3.1
BUILDLINK_ABI_DEPENDS.mpc+=	mpc>=1.3.1
BUILDLINK_PKGSRCDIR.mpc?=	../../math/mpc

.include "../../math/mpfr/buildlink3.mk"
.endif # MPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpc
