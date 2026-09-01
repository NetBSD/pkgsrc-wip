# $NetBSD: $

BUILDLINK_TREE+=	temurin-jdk17

.if !defined(TEMURIN_JDK17_BUILDLINK3_MK)
TEMURIN_JDK17_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.temurin-jdk17+=	temurin-jdk17-[0-9]*
BUILDLINK_ABI_DEPENDS.temurin-jdk17+=	temurin-jdk17>=17.0.5
BUILDLINK_PKGSRCDIR.temurin-jdk17?=	../../lang/temurin-jdk17
BUILDLINK_JAVA_PREFIX.temurin-jdk17=	${PREFIX}/java/temurin-jdk17

UNLIMIT_RESOURCES+=	datasize
.endif # TEMURIN_JDK17_BUILDLINK3_MK

BUILDLINK_TREE+=	-temurin-jdk17
