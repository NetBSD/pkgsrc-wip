# $NetBSD: buildlink3.mk,v 1.4 2011/01/07 10:15:58 phonohawk Exp $

BUILDLINK_TREE+=	hs-regex-compat

.if !defined(HS_REGEX_COMPAT_BUILDLINK3_MK)
HS_REGEX_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-compat+=	hs-regex-compat>=0.93
BUILDLINK_PKGSRCDIR.hs-regex-compat?=	../../wip/hs-regex-compat

.include "../../wip/hs-regex-base/buildlink3.mk"
.include "../../wip/hs-regex-posix/buildlink3.mk"
.endif	# HS_REGEX_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-compat
