# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	cpphs

.if !defined(CPPHS_BUILDLINK3_MK)
CPPHS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.cpphs?=	build
BUILDLINK_API_DEPENDS.cpphs+=	cpphs>=1.6
BUILDLINK_PKGSRCDIR.cpphs?=	../../wip/cpphs
.endif # CPPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cpphs
