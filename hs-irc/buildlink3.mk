# $NetBSD: buildlink3.mk,v 1.4 2014/05/19 21:28:49 szptvlfn Exp $
#

BUILDLINK_TREE+=	hs-irc

.if !defined(HS_IRC_BUILDLINK3_MK)
HS_IRC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-irc+=	hs-irc>=0.4.4.2
BUILDLINK_PKGSRCDIR.hs-irc?=	../../wip/hs-irc

.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_IRC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-irc
