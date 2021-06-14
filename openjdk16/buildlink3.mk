# $NetBSD: buildlink3.mk,v 1.1 2019/10/02 13:10:23 ryoon Exp $

BUILDLINK_TREE+=	openjdk16

.if !defined(OPENJDK16_BUILDLINK3_MK)
OPENJDK16_BUILDLINK3_MK:=

LIBDIR_ARCH=			${MACHINE_ARCH:S/x86_64/amd64/:S/sparc64/sparcv9/:C/^e?arm.*$/arm/}
BUILDLINK_LIBDIRS.openjdk16+=	java/openjdk16/jre/lib/${LIBDIR_ARCH}/server
BUILDLINK_LIBDIRS.openjdk16+=	java/openjdk16/jre/lib/${LIBDIR_ARCH}

BUILDLINK_API_DEPENDS.openjdk16+=	openjdk16>=1.16.0.1
BUILDLINK_PKGSRCDIR.openjdk16?=		../../lang/openjdk16

.endif	# OPENJDK16_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjdk16
