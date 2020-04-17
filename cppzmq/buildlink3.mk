# $NetBSD$

BUILDLINK_TREE+=	cppzmq

.if !defined(CPPZMQ_BUILDLINK3_MK)
CPPZMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cppzmq+=	cppzmq>=4.6.0
BUILDLINK_PKGSRCDIR.cppzmq?=	../../wip/cppzmq
BUILDLINK_DEPMETHOD.cppzmq?=	build

.include "../../net/zeromq/buildlink3.mk"
.endif	# CPPZMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-cppzmq
