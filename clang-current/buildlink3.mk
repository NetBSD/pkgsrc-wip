# $NetBSD: buildlink3.mk,v 1.2 2011/08/08 14:15:12 asau Exp $

BUILDLINK_TREE+=	clang

.if !defined(CLANG_BUILDLINK3_MK)
CLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clang+=	clang>=2.6nb2
BUILDLINK_PKGSRCDIR.clang?=	../../wip/clang

.endif	# CLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-clang
