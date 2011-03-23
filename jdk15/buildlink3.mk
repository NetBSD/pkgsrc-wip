# $NetBSD: buildlink3.mk,v 1.9 2011/03/23 05:16:04 obache Exp $

BUILDLINK_TREE+=	jdk15

.if !defined(JDK15_BUILDLINK3_MK)
JDK15_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jdk15+=	jdk15>=1.5.0.2
BUILDLINK_PKGSRCDIR.jdk15?=	../../wip/jdk15
BUILDLINK_JAVA_PREFIX.jdk15=	${PREFIX}/java/jdk-1.5.0

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.jdk15}

BUILDLINK_CPPFLAGS.jdk15= \
	-I${BUILDLINK_JAVA_PREFIX.jdk15}/include	\
	-I${BUILDLINK_JAVA_PREFIX.jdk15}/include/${LOWER_OPSYS}

.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif # JDK15_BUILDLINK3_MK

BUILDLINK_TREE+=	-jdk15
