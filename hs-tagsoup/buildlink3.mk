# $NetBSD: buildlink3.mk,v 1.8 2014/05/18 21:33:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-tagsoup

.if !defined(HS_TAGSOUP_BUILDLINK3_MK)
HS_TAGSOUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagsoup+=	hs-tagsoup>=0.13.1
BUILDLINK_PKGSRCDIR.hs-tagsoup?=	../../wip/hs-tagsoup

.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_TAGSOUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagsoup
