# $NetBSD: buildlink3.mk,v 1.5 2010/02/17 14:55:48 phonohawk Exp $

BUILDLINK_TREE+=	hs-HsOpenSSL

.if !defined(HS_HSOPENSSL_BUILDLINK3_MK)
HS_HSOPENSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HsOpenSSL+=	hs-HsOpenSSL>=0.8
BUILDLINK_PKGSRCDIR.hs-HsOpenSSL?=	../../wip/hs-HsOpenSSL

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.endif	# HS_HSOPENSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HsOpenSSL
