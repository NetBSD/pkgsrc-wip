# $NetBSD$

BUILDLINK_TREE+=	belle-sip

.if !defined(BELLE_SIP_BUILDLINK3_MK)
BELLE_SIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.belle-sip+=	belle-sip>=1.4.2
BUILDLINK_PKGSRCDIR.belle-sip?=		../../wip/belle-sip

#.include "../../wip/antlr3-c/buildlink3.mk"
.endif	# BELLE_SIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-belle-sip
