# $NetBSD$

BUILDLINK_TREE+=	galera

.if !defined(GALERA_BUILDLINK3_MK)
GALERA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.galera+=	galera>=26.4.13
BUILDLINK_PKGSRCDIR.galera?=	../../wip/galera

.include "../../security/openssl/buildlink3.mk"
.endif	# GALERA_BUILDLINK3_MK

BUILDLINK_TREE+=	-galera
