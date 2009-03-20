# $NetBSD: buildlink3.mk,v 1.16 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	edje

.if !defined(EDJE_BUILDLINK3_MK)
EDJE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edje+=	edje>=0.9.9.043
BUILDLINK_ABI_DEPENDS.edje?=	edje>=0.9.9.043nb1
BUILDLINK_PKGSRCDIR.edje?=	../../wip/edje

.include	"../../devel/eet/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"
.include	"../../graphics/evas/buildlink3.mk"
.include	"../../lang/embryo/buildlink3.mk"
.endif # EDJE_BUILDLINK3_MK

BUILDLINK_TREE+=	-edje
