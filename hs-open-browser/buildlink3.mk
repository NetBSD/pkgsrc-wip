# $NetBSD$

BUILDLINK_TREE+=	hs-open-browser

.if !defined(HS_OPEN_BROWSER_BUILDLINK3_MK)
HS_OPEN_BROWSER_BUILDLINK3_MK:=	# defined

BUILDLINK_API_DEPENDS.hs-open-browser+=	hs-open-browser>=0.2.1.0
BUILDLINK_ABI_DEPENDS.hs-open-browser+=	hs-open-browser>=0.2.1.0
BUILDLINK_PKGSRCDIR.hs-open-browser?=	../../wip/hs-open-browser

.endif	# HS_OPEN_BROWSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-open-browser
