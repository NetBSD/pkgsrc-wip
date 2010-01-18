# $NetBSD: buildlink3.mk,v 1.6 2010/01/18 09:38:20 thomasklausner Exp $

BUILDLINK_TREE+=	entrance

.if !defined(ENTRANCE_BUILDLINK3_MK)
ENTRANCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.entrance+=	entrance>=0.9.9.042nb1
BUILDLINK_ABI_DEPENDS.entrance?=	entrance>=0.9.9.050nb2
BUILDLINK_PKGSRCDIR.entrance?=	../../wip/entrance

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../graphics/evas/buildlink3.mk"
.include	"../../wip/edje/buildlink3.mk"
.include	"../../wip/esmart/buildlink3.mk"
.include	"../../wip/efreet/buildlink3.mk"
.endif # ENTRANCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-entrance
