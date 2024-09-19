# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-irc

.if !defined(HS_IRC_BUILDLINK3_MK)
HS_IRC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-irc+=	hs-irc>=0.4.4
BUILDLINK_ABI_DEPENDS.hs-irc+=	hs-irc>=0.4.4.2
BUILDLINK_PKGSRCDIR.hs-irc?=	../../wip/hs-irc

.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_IRC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-irc
