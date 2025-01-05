# $NetBSD$

BUILDLINK_TREE+=	libfixposix

.if !defined(LIBFIXPOSIX_BUILDLINK3_MK)
LIBFIXPOSIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfixposix+=	libfixposix>=0.4.3
BUILDLINK_PKGSRCDIR.libfixposix?=	../../wip/libfixposix

.include "../../mk/pthread.buildlink3.mk"
.endif	# LIBFIXPOSIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfixposix
