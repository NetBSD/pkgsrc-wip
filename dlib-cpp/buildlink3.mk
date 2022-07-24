# $NetBSD: buildlink3.mk,v 1.5 2017/02/28 14:40:47 ryoon Exp $

BUILDLINK_TREE+=	dlib-cpp

.if !defined(DLIB_CPP_BUILDLINK3_MK)
DLIB_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dlib-cpp+=	dlib-cpp>=19.24
BUILDLINK_ABI_DEPENDS.dlib-cpp+=	dlib-cpp>=19.24
BUILDLINK_PKGSRCDIR.dlib-cpp?=		../../wip/dlib-cpp

.endif	# DLIB_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-dlib-cpp
