# $NetBSD$

BUILDLINK_TREE+=	execline

.if !defined(EXECLINE_BUILDLINK3_MK)
EXECLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.execline+=	execline>=2.2.0.0
BUILDLINK_PKGSRCDIR.execline?=		../../wip/execline

.include "../../devel/skalibs/buildlink3.mk"
.endif # EXECLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-execline
