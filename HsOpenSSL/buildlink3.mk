# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:39 jsonn Exp $

BUILDLINK_TREE+=	HsOpenSSL

.if !defined(HSOPENSSL_BUILDLINK3_MK)
HSOPENSSL_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.HsOpenSSL?=	build
BUILDLINK_API_DEPENDS.HsOpenSSL+=	HsOpenSSL>=0.5.1
BUILDLINK_PKGSRCDIR.HsOpenSSL?=	../../wip/HsOpenSSL

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.endif # HSOPENSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-HsOpenSSL
