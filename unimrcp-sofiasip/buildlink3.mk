# $NetBSD$

BUILDLINK_TREE+=	sofia-sip-1.12.11-204

.if !defined(SOFIA_SIP_1.12.11_204_BUILDLINK3_MK)
SOFIA_SIP_1.12.11_204_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sofia-sip-1.12.11-204+=	sofia-sip>=1.12.11
BUILDLINK_ABI_DEPENDS.sofia-sip-1.12.11-204?=	sofia-sip>=1.12.11
BUILDLINK_PKGSRCDIR.sofia-sip-1.12.11-204?=	../../wip/unimrcp-sofiasip

.include "../../security/openssl/buildlink3.mk"
.endif	# SOFIA_SIP_1.12.11_204_BUILDLINK3_MK

BUILDLINK_TREE+=	-sofia-sip-1.12.11-204
