# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/05/12 11:50:56 ryo-on Exp $

BUILDLINK_TREE+=	gtest

.if !defined(GTEST_BUILDLINK3_MK)
GTEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtest+=	gtest>=1.6.0
BUILDLINK_PKGSRCDIR.gtest?=	../../wip/gtest
.endif	# GTEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtest
