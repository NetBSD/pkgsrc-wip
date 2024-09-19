# $NetBSD: buildlink3.mk,v 1.8 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-regex-compat

.if !defined(HS_REGEX_COMPAT_BUILDLINK3_MK)
HS_REGEX_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-compat+=	hs-regex-compat>=0.95.1
BUILDLINK_ABI_DEPENDS.hs-regex-compat+=	hs-regex-compat>=0.95.1
BUILDLINK_PKGSRCDIR.hs-regex-compat?=	../../wip/hs-regex-compat

.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../textproc/hs-regex-posix/buildlink3.mk"
.endif	# HS_REGEX_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-compat
