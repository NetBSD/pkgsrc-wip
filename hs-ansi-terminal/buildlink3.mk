# $NetBSD: buildlink3.mk,v 1.4 2013/12/25 19:12:26 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ansi-terminal

.if !defined(HS_ANSI_TERMINAL_BUILDLINK3_MK)
HS_ANSI_TERMINAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-terminal+=	hs-ansi-terminal>=0.6.1
BUILDLINK_PKGSRCDIR.hs-ansi-terminal?=	../../wip/hs-ansi-terminal
.endif	# HS_ANSI_TERMINAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-terminal
