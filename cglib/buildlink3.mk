# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/09/02 12:10:01 jihbed Exp $

BUILDLINK_TREE+=	cglib

.if !defined(CGLIB_BUILDLINK3_MK)
CGLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cglib+=	cglib>=2.2
BUILDLINK_PKGSRCDIR.cglib?=	../../wip/cglib
.endif	# CGLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cglib
