# $NetBSD: buildlink3.mk,v 1.23 2012/12/30 19:47:55 roelants Exp $

BUILDLINK_TREE+=	edje

.if !defined(EDJE_BUILDLINK3_MK)
EDJE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edje+=	edje>=1.7.0
BUILDLINK_PKGSRCDIR.edje?=	../../wip/edje

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/eet/buildlink3.mk"
.include	"../../wip/eio/buildlink3.mk"
.include	"../../wip/evas/buildlink3.mk"
.include	"../../wip/embryo/buildlink3.mk"
.include	"../../lang/lua/buildlink3.mk"
.endif # EDJE_BUILDLINK3_MK

BUILDLINK_TREE+=	-edje
