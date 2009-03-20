# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	hs-regex-compat

.if !defined(HS_REGEX_COMPAT_BUILDLINK3_MK)
HS_REGEX_COMPAT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-regex-compat?=	build
BUILDLINK_API_DEPENDS.hs-regex-compat+=	hs-regex-compat>=0.92
BUILDLINK_PKGSRCDIR.hs-regex-compat?=	../../wip/hs-regex-compat

.include "../../wip/hs-regex-base/buildlink3.mk"
.include "../../wip/hs-regex-posix/buildlink3.mk"
.endif # HS_REGEX_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-compat
