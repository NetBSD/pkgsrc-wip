# $NetBSD: buildlink3.mk,v 1.1 2014/11/22 10:31:06 jihbed Exp $

BUILDLINK_TREE+=	kstest

.if !defined(KSTEST_BUILDLINK3_MK)
KSTEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kstest+=	kstest>=2.0.0
BUILDLINK_PKGSRCDIR.kstest?=	../../wip/kstest
.endif	# KSTEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-kstest
