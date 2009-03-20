# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	dumb

.if !defined(DUMB_BUILDLINK3_MK)
DUMB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dumb+=	dumb>=0.9.2
BUILDLINK_PKGSRCDIR.dumb?=	../../wip/dumb

.include "../../devel/allegro/buildlink3.mk"
.endif # DUMB_BUILDLINK3_MK

BUILDLINK_TREE+=	-dumb
