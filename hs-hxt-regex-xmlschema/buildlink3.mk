# $NetBSD: buildlink3.mk,v 1.2 2012/02/11 04:15:36 phonohawk Exp $

BUILDLINK_TREE+=	hs-hxt-regex-xmlschema

.if !defined(HS_HXT_REGEX_XMLSCHEMA_BUILDLINK3_MK)
HS_HXT_REGEX_XMLSCHEMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-regex-xmlschema+=	hs-hxt-regex-xmlschema>=9.0.4
BUILDLINK_PKGSRCDIR.hs-hxt-regex-xmlschema?=	../../wip/hs-hxt-regex-xmlschema

.include "../../wip/hs-hxt-charproperties/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_HXT_REGEX_XMLSCHEMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-regex-xmlschema
