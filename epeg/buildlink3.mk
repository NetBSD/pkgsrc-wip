# $NetBSD: buildlink3.mk,v 1.11 2010/01/18 09:38:20 thomasklausner Exp $

BUILDLINK_TREE+=	epeg

.if !defined(EPEG_BUILDLINK3_MK)
EPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.epeg+=	epeg>=0.9.1.042
BUILDLINK_ABI_DEPENDS.epeg?=	epeg>=0.9.1.042nb3
BUILDLINK_PKGSRCDIR.epeg?=	../../wip/epeg

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../graphics/jpeg/buildlink3.mk"
.endif # EPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-epeg
