# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:35:24 wiz Exp $

BUILDLINK_TREE+=	openmp

.if !defined(OPENMP_BUILDLINK3_MK)
OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmp+=	openmp>=19.1.0
BUILDLINK_ABI_DEPENDS.openmp+=	openmp>=19.1.0
BUILDLINK_PKGSRCDIR.openmp?=	../../wip/openmp
.endif	# OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmp
