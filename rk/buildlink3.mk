# $NetBSD: buildlink3.mk,v 1.1 2014/11/22 19:32:37 jihbed Exp $

BUILDLINK_TREE+=	rk

.if !defined(RK_BUILDLINK3_MK)
RK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rk+=	rk>=1.5
BUILDLINK_PKGSRCDIR.rk?=	../../wip/rk
.endif	# RK_BUILDLINK3_MK

BUILDLINK_TREE+=	-rk
