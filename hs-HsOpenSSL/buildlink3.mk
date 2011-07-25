# $NetBSD: buildlink3.mk,v 1.6 2011/07/25 16:31:36 phonohawk Exp $

BUILDLINK_TREE+=	hs-HsOpenSSL

.if !defined(HS_HSOPENSSL_BUILDLINK3_MK)
HS_HSOPENSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HsOpenSSL+=	hs-HsOpenSSL>=0.10
BUILDLINK_PKGSRCDIR.hs-HsOpenSSL?=	../../wip/hs-HsOpenSSL

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.endif	# HS_HSOPENSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HsOpenSSL
