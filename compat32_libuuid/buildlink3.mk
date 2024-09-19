# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/08 20:40:33 markd Exp $

BUILDLINK_TREE+=	compat32_libuuid

.if !defined(COMPAT32_LIBUUID_BUILDLINK3_MK)
COMPAT32_LIBUUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_libuuid+=	compat32_libuuid>=2.18
BUILDLINK_PKGSRCDIR.compat32_libuuid?=		../../wip/compat32_libuuid
BUILDLINK_LIBDIRS.compat32_libuuid=		emul/netbsd32/lib
BUILDLINK_INCDIRS.compat32_libuuid=		emul/netbsd32/include/uuid
.endif	# COMPAT32_LIBUUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_libuuid
