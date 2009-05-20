# $NetBSD: buildlink3.mk,v 1.3 2009/05/20 00:58:41 thomasklausner Exp $

BUILDLINK_TREE+=	hs-readline

.if !defined(HS_READLINE_BUILDLINK3_MK)
HS_READLINE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-readline?=	build
BUILDLINK_API_DEPENDS.hs-readline+=	hs-readline>=1.0.1.0
BUILDLINK_ABI_DEPENDS.hs-readline?=	hs-readline>=1.0.1.0nb1
BUILDLINK_PKGSRCDIR.hs-readline?=	../../wip/hs-readline

.include "../../devel/readline/buildlink3.mk"
.endif # HS_READLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-readline
