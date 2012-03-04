# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 07:47:44 phonohawk Exp $

BUILDLINK_TREE+=	hs-executable-path

.if !defined(HS_EXECUTABLE_PATH_BUILDLINK3_MK)
HS_EXECUTABLE_PATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-executable-path+=	hs-executable-path>=0.0.3
BUILDLINK_PKGSRCDIR.hs-executable-path?=	../../wip/hs-executable-path
.endif	# HS_EXECUTABLE_PATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-executable-path
