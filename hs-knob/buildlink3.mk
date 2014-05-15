# $NetBSD: buildlink3.mk,v 1.2 2014/05/15 21:49:08 szptvlfn Exp $

BUILDLINK_TREE+=	hs-knob

.if !defined(HS_KNOB_BUILDLINK3_MK)
HS_KNOB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-knob+=	hs-knob>=0.1.1
BUILDLINK_PKGSRCDIR.hs-knob?=	../../wip/hs-knob

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_KNOB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-knob
