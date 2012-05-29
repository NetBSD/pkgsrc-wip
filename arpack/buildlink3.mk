# $NetBSD: buildlink3.mk,v 1.3 2012/05/29 16:21:58 asau Exp $

BUILDLINK_DEPMETHOD.arpack?=	build

BUILDLINK_TREE+=	arpack

.if !defined(ARPACK_BUILDLINK3_MK)
ARPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arpack+=	arpack>=96
BUILDLINK_PKGSRCDIR.arpack?=	../../wip/arpack
.endif	# ARPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-arpack
