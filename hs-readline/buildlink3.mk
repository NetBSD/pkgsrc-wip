# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	hs-readline

.if !defined(HS_READLINE_BUILDLINK3_MK)
HS_READLINE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-readline?=	build
BUILDLINK_API_DEPENDS.hs-readline+=	hs-readline>=1.0.1.0
BUILDLINK_PKGSRCDIR.hs-readline?=	../../wip/hs-readline

.include "../../devel/readline/buildlink3.mk"
.endif # HS_READLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-readline
