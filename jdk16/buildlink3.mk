# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	jdk16

.if !defined(JDK15_BUILDLINK3_MK)
JDK15_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jdk15+=	jdk16>=1.6.0.0
BUILDLINK_PKGSRCDIR.jdk15?=	../../wip/jdk16
BUILDLINK_JAVA_PREFIX.jdk15=	${PREFIX}/java/jdk-1.6.0

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.jdk16}

BUILDLINK_CPPFLAGS.jdk16= \
	-I${BUILDLINK_JAVA_PREFIX.jdk16}/include	\
	-I${BUILDLINK_JAVA_PREFIX.jdk16}/include/netbsd
.endif	# JDK16_BUILDLINK3_MK

.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif # JDK15_BUILDLINK3_MK

BUILDLINK_TREE+=	-jdk16
