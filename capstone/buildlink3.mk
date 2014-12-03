# $NetBSD: buildlink3.mk,v 1.1 2014/12/03 23:47:19 krytarowski Exp $

BUILDLINK_TREE+=	capstone

.if !defined(CAPSTONE_BUILDLINK3_MK)
CAPSTONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.capstone+=	capstone>=3.0
BUILDLINK_ABI_DEPENDS.capstone+=	capstone>=3.0
BUILDLINK_PKGSRCDIR.capstone?=	../../wip/capstone
.endif	# CAPSTONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-capstone
