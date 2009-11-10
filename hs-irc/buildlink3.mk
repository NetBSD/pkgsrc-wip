# $NetBSD: buildlink3.mk,v 1.3 2009/11/10 03:28:55 phonohawk Exp $
#

BUILDLINK_TREE+=	hs-irc

.if !defined(HS_IRC_BUILDLINK3_MK)
HS_IRC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-irc+=	hs-irc>=0.4.4.2
BUILDLINK_PKGSRCDIR.hs-irc?=	../../wip/hs-irc

.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_IRC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-irc
