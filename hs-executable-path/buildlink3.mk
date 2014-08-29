# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:12 szptvlfn Exp $

BUILDLINK_TREE+=	hs-executable-path

.if !defined(HS_EXECUTABLE_PATH_BUILDLINK3_MK)
HS_EXECUTABLE_PATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-executable-path+=	hs-executable-path>=0.0.3
BUILDLINK_ABI_DEPENDS.hs-executable-path+=	hs-executable-path>=0.0.3
BUILDLINK_PKGSRCDIR.hs-executable-path?=	../../wip/hs-executable-path
.endif	# HS_EXECUTABLE_PATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-executable-path
