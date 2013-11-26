# $NetBSD: buildlink3.mk,v 1.1 2013/11/26 23:52:59 szptvlfn Exp $

BUILDLINK_TREE+=	hs-http-attoparsec

.if !defined(HS_HTTP_ATTOPARSEC_BUILDLINK3_MK)
HS_HTTP_ATTOPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-attoparsec+=	hs-http-attoparsec>=0.1.0
BUILDLINK_PKGSRCDIR.hs-http-attoparsec?=	../../wip/hs-http-attoparsec

.include "../../wip/hs-attoparsec/buildlink3.mk"
.include "../../wip/hs-http-types/buildlink3.mk"
.endif	# HS_HTTP_ATTOPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-attoparsec
