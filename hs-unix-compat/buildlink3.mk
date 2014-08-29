# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-unix-compat

.if !defined(HS_UNIX_COMPAT_BUILDLINK3_MK)
HS_UNIX_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unix-compat+=	hs-unix-compat>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-unix-compat+=	hs-unix-compat>=0.4.1.1
BUILDLINK_PKGSRCDIR.hs-unix-compat?=	../../wip/hs-unix-compat
.endif	# HS_UNIX_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unix-compat
