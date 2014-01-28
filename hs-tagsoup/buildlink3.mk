# $NetBSD: buildlink3.mk,v 1.7 2014/01/28 22:56:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-tagsoup

.if !defined(HS_TAGSOUP_BUILDLINK3_MK)
HS_TAGSOUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagsoup+=	hs-tagsoup>=0.13.1
BUILDLINK_PKGSRCDIR.hs-tagsoup?=	../../wip/hs-tagsoup

.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_TAGSOUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagsoup
