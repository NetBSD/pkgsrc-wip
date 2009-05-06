# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 09:56:57 cheusov Exp $

BUILDLINK_TREE+=	phlib

.if !defined(PHLIB_BUILDLINK3_MK)
PHLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.phlib+=	phlib>=1.20
BUILDLINK_PKGSRCDIR.phlib?=	../../wip/phlib
.endif # PHLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-phlib
