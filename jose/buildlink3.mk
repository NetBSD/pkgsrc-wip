# $NetBSD: buildlink3.mk,v 1.2 2020/01/18 21:48:26 jperkin Exp $

BUILDLINK_TREE+=	jose

.if !defined(JOSE_BUILDLINK3_MK)
JOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jose+=	jose>=11
BUILDLINK_ABI_DEPENDS.jose+=	jose>=11
BUILDLINK_PKGSRCDIR.jose?=	../../wip/jose

.include "../../textproc/jansson/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# JOSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-jose
