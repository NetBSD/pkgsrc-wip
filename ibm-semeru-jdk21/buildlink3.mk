# $NetBSD$

BUILDLINK_TREE+=	ibm-semeru-jdk21

.if !defined(IBM-SEMERU_JDK21_BUILDLINK3_MK)
IBM-SEMERU_JDK21_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ibm-semeru-jdk21+=	ibm-semeru-jdk21-[0-9]*
BUILDLINK_ABI_DEPENDS.ibm-semeru-jdk21+=	ibm-semeru-jdk21>=21.0.5
BUILDLINK_PKGSRCDIR.ibm-semeru-jdk21?=		../../wip/ibm-semeru-jdk21
BUILDLINK_JAVA_PREFIX.ibm-semeru-jdk21=		${PREFIX}/java/ibm-semeru-jdk21

UNLIMIT_RESOURCES+=	datasize
.endif # IBM-SEMERU_JDK21_BUILDLINK3_MK

BUILDLINK_TREE+=	-ibm-semeru-jdk21
