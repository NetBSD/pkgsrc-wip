# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	uniplate

.if !defined(UNIPLATE_BUILDLINK3_MK)
UNIPLATE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.uniplate?=	build
BUILDLINK_API_DEPENDS.uniplate+=	uniplate>=1.2.0.3
BUILDLINK_PKGSRCDIR.uniplate?=	../../wip/uniplate
.endif # UNIPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-uniplate
