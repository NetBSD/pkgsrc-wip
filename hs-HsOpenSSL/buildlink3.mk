# $NetBSD: buildlink3.mk,v 1.3 2010/01/17 12:03:26 thomasklausner Exp $

BUILDLINK_TREE+=	hs-HsOpenSSL

.if !defined(HS_HSOPENSSL_BUILDLINK3_MK)
HS_HSOPENSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HsOpenSSL+=	hs-HsOpenSSL>=0.6.5
BUILDLINK_ABI_DEPENDS.hs-HsOpenSSL?=	hs-HsOpenSSL>=0.6.5nb1
BUILDLINK_PKGSRCDIR.hs-HsOpenSSL?=	../../wip/hs-HsOpenSSL

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.endif	# HS_HSOPENSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HsOpenSSL
