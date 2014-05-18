# $NetBSD: buildlink3.mk,v 1.5 2014/05/18 21:33:26 szptvlfn Exp $

BUILDLINK_TREE+=	hs-blaze-html

.if !defined(HS_BLAZE_HTML_BUILDLINK3_MK)
HS_BLAZE_HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-html+=	hs-blaze-html>=0.7.0
BUILDLINK_PKGSRCDIR.hs-blaze-html?=	../../wip/hs-blaze-html

.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_BLAZE_HTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-html
