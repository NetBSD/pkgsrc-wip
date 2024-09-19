# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hxt-tagsoup

.if !defined(HS_HXT_TAGSOUP_BUILDLINK3_MK)
HS_HXT_TAGSOUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-tagsoup+=	hs-hxt-tagsoup>=9.1.1
BUILDLINK_ABI_DEPENDS.hs-hxt-tagsoup+=	hs-hxt-tagsoup>=9.1.1
BUILDLINK_PKGSRCDIR.hs-hxt-tagsoup?=	../../wip/hs-hxt-tagsoup

.include "../../textproc/hs-hxt/buildlink3.mk"
.include "../../textproc/hs-hxt-charproperties/buildlink3.mk"
.include "../../textproc/hs-hxt-unicode/buildlink3.mk"
.include "../../textproc/hs-tagsoup/buildlink3.mk"
.endif	# HS_HXT_TAGSOUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-tagsoup
