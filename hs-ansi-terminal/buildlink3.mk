# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/06 15:23:07 phonohawk Exp $

BUILDLINK_TREE+=	hs-ansi-terminal

.if !defined(HS_ANSI_TERMINAL_BUILDLINK3_MK)
HS_ANSI_TERMINAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-terminal+=	hs-ansi-terminal>=0.5
BUILDLINK_PKGSRCDIR.hs-ansi-terminal?=	../../wip/hs-ansi-terminal
.endif	# HS_ANSI_TERMINAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-terminal
