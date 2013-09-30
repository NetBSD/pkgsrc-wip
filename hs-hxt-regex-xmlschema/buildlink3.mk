# $NetBSD: buildlink3.mk,v 1.3 2013/09/30 23:05:23 phonohawk Exp $

BUILDLINK_TREE+=	hs-hxt-regex-xmlschema

.if !defined(HS_HXT_REGEX_XMLSCHEMA_BUILDLINK3_MK)
HS_HXT_REGEX_XMLSCHEMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-regex-xmlschema+=	hs-hxt-regex-xmlschema>=9.1.0
BUILDLINK_PKGSRCDIR.hs-hxt-regex-xmlschema?=	../../wip/hs-hxt-regex-xmlschema

.include "../../wip/hs-hxt-charproperties/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_HXT_REGEX_XMLSCHEMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-regex-xmlschema
