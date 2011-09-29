# $NetBSD: buildlink3.mk,v 1.1 2011/09/29 11:52:36 khorben Exp $

BUILDLINK_TREE+=	sofia-sip

.if !defined(SOFIA_SIP_BUILDLINK3_MK)
SOFIA_SIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sofia-sip+=	sofia-sip>=1.12.10
BUILDLINK_PKGSRCDIR.sofia-sip?=		../../wip/sofia-sip

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# SOFIA_SIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-sofia-sip
