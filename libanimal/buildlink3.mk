# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libanimal

.if !defined(LIBANIMAL_BUILDLINK3_MK)
LIBANIMAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libanimal+=	libanimal>=0.15.0
BUILDLINK_PKGSRCDIR.libanimal?=		../../wip/libanimal
.endif # LIBANIMAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libanimal
