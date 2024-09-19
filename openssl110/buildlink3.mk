# $NetBSD: buildlink3.mk,v 1.51 2016/03/05 11:27:55 jperkin Exp $

BUILDLINK_TREE+=	openssl

.if !defined(OPENSSL_BUILDLINK3_MK)
OPENSSL_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.openssl+=	openssl>=1.1.0f
BUILDLINK_ABI_DEPENDS.openssl+=	openssl>=1.1.0f
BUILDLINK_PKGSRCDIR.openssl?=	../../security/openssl

SSLBASE=	${BUILDLINK_PREFIX.openssl}
BUILD_DEFS+=	SSLBASE

.endif # OPENSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openssl
