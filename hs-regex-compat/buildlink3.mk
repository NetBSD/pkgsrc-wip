# $NetBSD: buildlink3.mk,v 1.3 2009/05/21 04:53:25 phonohawk Exp $

BUILDLINK_TREE+=	hs-regex-compat

.if !defined(HS_REGEX_COMPAT_BUILDLINK3_MK)
HS_REGEX_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-compat+=	hs-regex-compat>=0.92nb1
BUILDLINK_PKGSRCDIR.hs-regex-compat?=	../../wip/hs-regex-compat

.include "../../wip/hs-regex-base/buildlink3.mk"
.include "../../wip/hs-regex-posix/buildlink3.mk"
.endif	# HS_REGEX_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-compat
