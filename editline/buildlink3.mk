# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	editline

.if !defined(EDITLINE_BUILDLINK3_MK)
EDITLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.editline+=	editline>=2.11
BUILDLINK_PKGSRCDIR.editline?=	../../wip/editline
.endif # EDITLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-editline
