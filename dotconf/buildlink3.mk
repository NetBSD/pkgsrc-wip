# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	dotconf

.if !defined(DOTCONF_BUILDLINK3_MK)
DOTCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dotconf+=	dotconf>=1.0.13
BUILDLINK_PKGSRCDIR.dotconf?=	../../wip/dotconf
.endif # DOTCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-dotconf
