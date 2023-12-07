# $NetBSD$

BUILDLINK_TREE+=	libnsl

.if !defined(LIBNSL_BUILDLINK3_MK)
LIBNSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnsl+=	libnsl>=2.0.1
BUILDLINK_PKGSRCDIR.libnsl?=	../../wip/libnsl

.include "../../devel/libtirpc/buildlink3.mk"
.endif	# LIBNSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnsl
