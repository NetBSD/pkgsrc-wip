# $NetBSD$

BUILDLINK_TREE+=	execline

.if !defined(EXECLINE_BUILDLINK3_MK)
EXECLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.execline+=	execline>=2.1.4.5
BUILDLINK_PKGSRCDIR.execline?=		../../wip/execline

.include "../../wip/skalibs/buildlink3.mk"
.endif # EXECLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-execline
