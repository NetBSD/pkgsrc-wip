# $NetBSD$

BUILDLINK_TREE+=	libfixposix

.if !defined(LIBFIXPOSIX_BUILDLINK3_MK)
LIBFIXPOSIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfixposix+=	libfixposix>=v0.4.3
BUILDLINK_PKGSRCDIR.libfixposix?=	../../wip/libfixposix

.endif	# LIBFIXPOSIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfixposix
