# $NetBSD: buildlink3.mk,v 1.2 2012/03/23 02:26:48 outpaddling Exp $

BUILDLINK_TREE+=	arpack

.if !defined(ARPACK_BUILDLINK3_MK)
ARPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arpack+=	arpack>=96
BUILDLINK_PKGSRCDIR.arpack?=	../../wip/arpack
.endif	# ARPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-arpack
