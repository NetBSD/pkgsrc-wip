# $NetBSD: buildlink3.mk,v 1.20 2010/01/18 09:38:19 thomasklausner Exp $

BUILDLINK_TREE+=	edje

.if !defined(EDJE_BUILDLINK3_MK)
EDJE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edje+=	edje>=0.9.9.062
BUILDLINK_ABI_DEPENDS.edje?=	edje>=0.9.92.062nb2
BUILDLINK_PKGSRCDIR.edje?=	../../wip/edje

.include	"../../devel/eet/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"
.include	"../../graphics/evas/buildlink3.mk"
.include	"../../lang/embryo/buildlink3.mk"
.endif # EDJE_BUILDLINK3_MK

BUILDLINK_TREE+=	-edje
