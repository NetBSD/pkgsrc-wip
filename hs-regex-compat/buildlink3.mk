# $NetBSD: buildlink3.mk,v 1.5 2013/06/05 22:11:21 szptvlfn Exp $

BUILDLINK_TREE+=	hs-regex-compat

.if !defined(HS_REGEX_COMPAT_BUILDLINK3_MK)
HS_REGEX_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-compat+=	hs-regex-compat>=0.95
BUILDLINK_PKGSRCDIR.hs-regex-compat?=	../../wip/hs-regex-compat

.include "../../wip/hs-regex-base/buildlink3.mk"
.include "../../wip/hs-regex-posix/buildlink3.mk"
.endif	# HS_REGEX_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-compat
