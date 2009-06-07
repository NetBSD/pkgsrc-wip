# $NetBSD: buildlink3.mk,v 1.17 2009/06/07 21:27:03 jsonn Exp $

BUILDLINK_TREE+=	edje

.if !defined(EDJE_BUILDLINK3_MK)
EDJE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edje+=	edje>=0.9.9.060
BUILDLINK_PKGSRCDIR.edje?=	../../wip/edje

.include	"../../devel/eet/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"
.include	"../../graphics/evas/buildlink3.mk"
.include	"../../lang/embryo/buildlink3.mk"
.endif # EDJE_BUILDLINK3_MK

BUILDLINK_TREE+=	-edje
