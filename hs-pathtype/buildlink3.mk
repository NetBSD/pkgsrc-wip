# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/02 16:56:21 phonohawk Exp $

BUILDLINK_TREE+=	hs-pathtype

.if !defined(HS_PATHTYPE_BUILDLINK3_MK)
HS_PATHTYPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pathtype+=	hs-pathtype>=0.5.2
BUILDLINK_PKGSRCDIR.hs-pathtype?=	../../wip/hs-pathtype

.include "../../wip/hs-QuickCheck/buildlink3.mk"
.endif	# HS_PATHTYPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pathtype
