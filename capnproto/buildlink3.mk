# $NetBSD$

BUILDLINK_TREE+=	capnproto-c++

.if !defined(CAPNPROTO_C++_BUILDLINK3_MK)
CAPNPROTO_C++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.capnproto-c+++=	capnproto-c++>=0.8.0
BUILDLINK_PKGSRCDIR.capnproto-c++?=	../../wip/capnproto

.include "../../devel/zlib/buildlink3.mk"
.endif	# CAPNPROTO_C++_BUILDLINK3_MK

BUILDLINK_TREE+=	-capnproto-c++
