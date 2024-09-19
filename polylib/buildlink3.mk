# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/05/09 20:35:37 jihbed Exp $

BUILDLINK_TREE+=	polylib

.if !defined(POLYLIB_BUILDLINK3_MK)
POLYLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polylib+=	polylib>=5.22.5
BUILDLINK_PKGSRCDIR.polylib?=	../../wip/polylib
.endif	# POLYLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-polylib
