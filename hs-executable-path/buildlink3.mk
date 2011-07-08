# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/08 09:42:59 phonohawk Exp $

BUILDLINK_TREE+=	hs-executable-path

.if !defined(HS_EXECUTABLE_PATH_BUILDLINK3_MK)
HS_EXECUTABLE_PATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-executable-path+=	hs-executable-path>=0.0
BUILDLINK_PKGSRCDIR.hs-executable-path?=	../../wip/hs-executable-path
.endif	# HS_EXECUTABLE_PATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-executable-path
