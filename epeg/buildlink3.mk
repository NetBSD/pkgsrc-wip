# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:43:41 jsonn Exp $

BUILDLINK_TREE+=	epeg

.if !defined(EPEG_BUILDLINK3_MK)
EPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.epeg+=	epeg>=0.9.1.042
BUILDLINK_ABI_DEPENDS.epeg?=	epeg>=0.9.1.042nb1
BUILDLINK_PKGSRCDIR.epeg?=	../../wip/epeg

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../graphics/jpeg/buildlink3.mk"
.endif # EPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-epeg
