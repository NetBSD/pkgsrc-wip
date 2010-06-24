# $NetBSD: buildlink3.mk,v 1.1 2010/06/24 16:37:26 marko_schuetz Exp $

BUILDLINK_TREE+=	mpc

.if !defined(MPC_BUILDLINK3_MK)
MPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpc+=	mpc>=0.8.2
BUILDLINK_ABI_DEPENDS.mpc?=	mpc>=0.8.2
BUILDLINK_PKGSRCDIR.mpc?=	../../wip/mpc

.include "../../math/mpfr/buildlink3.mk"
.endif # MPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpc
