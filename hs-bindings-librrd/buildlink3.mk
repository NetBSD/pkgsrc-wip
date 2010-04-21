# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/21 03:39:30 phonohawk Exp $

BUILDLINK_TREE+=	hs-bindings-librrd

.if !defined(HS_BINDINGS_LIBRRD_BUILDLINK3_MK)
HS_BINDINGS_LIBRRD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bindings-librrd+=	hs-bindings-librrd>=0.1
BUILDLINK_PKGSRCDIR.hs-bindings-librrd?=	../../wip/hs-bindings-librrd

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../wip/hs-bindings-DSL/buildlink3.mk"
.endif	# HS_BINDINGS_LIBRRD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bindings-librrd
