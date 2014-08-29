# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:08 szptvlfn Exp $

BUILDLINK_TREE+=	hs-bindings-librrd

.if !defined(HS_BINDINGS_LIBRRD_BUILDLINK3_MK)
HS_BINDINGS_LIBRRD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bindings-librrd+=	hs-bindings-librrd>=0.1
BUILDLINK_ABI_DEPENDS.hs-bindings-librrd+=	hs-bindings-librrd>=0.1nb1
BUILDLINK_PKGSRCDIR.hs-bindings-librrd?=	../../wip/hs-bindings-librrd

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../wip/hs-bindings-DSL/buildlink3.mk"
.endif	# HS_BINDINGS_LIBRRD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bindings-librrd
