# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	phlib

BUILDLINK_API_DEPENDS.phlib+=	phlib>=1.20
BUILDLINK_PKGSRCDIR.phlib?=	../../wip/phlib
.endif # PHLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-phlib
