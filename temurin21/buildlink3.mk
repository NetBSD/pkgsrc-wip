# $NetBSD: $

BUILDLINK_TREE+=	temurin-jdk21

.if !defined(TEMURIN_JDK21_BUILDLINK3_MK)
TEMURIN_JDK21_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.temurin-jdk21+=	temurin-jdk21-[0-9]*
BUILDLINK_ABI_DEPENDS.temurin-jdk21+=	temurin-jdk21>=21.0.5
BUILDLINK_PKGSRCDIR.temurin-jdk21?=	../../lang/temurin-jdk21
BUILDLINK_JAVA_PREFIX.temurin-jdk21=	${PREFIX}/java/temurin-jdk21

UNLIMIT_RESOURCES+=	datasize
.endif # TEMURIN_JDK21_BUILDLINK3_MK

BUILDLINK_TREE+=	-temurin-jdk21
