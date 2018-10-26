# $NetBSD$

BUILDLINK_TREE+=	unittest-cpp

.if !defined(UNITTEST_CPP_BUILDLINK3_MK)
UNITTEST_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unittest-cpp+=	unittest-cpp>=2.0.0
BUILDLINK_PKGSRCDIR.unittest-cpp?=	../../wip/unittest-cpp
.endif	# UNITTEST_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-unittest-cpp
