# $NetBSD$

BUILDLINK_TREE+=	wolfssl

.if !defined(WOLFSSL_BUILDLINK3_MK)
WOLFSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wolfssl+=	wolfssl>=4.3.0
#BUILDLINK_PKGSRCDIR.wolfssl?=	../../security/wolfssl
BUILDLINK_PKGSRCDIR.wolfssl?=	../../wip/wolfssl

.endif # WOLFSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-wolfssl
