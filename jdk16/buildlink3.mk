# $NetBSD: buildlink3.mk,v 1.3 2009/06/02 13:17:21 noud4 Exp $

BUILDLINK_TREE+=	jdk16

.if !defined(JDK16_BUILDLINK3_MK)
JDK16_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jdk16+=	jdk16>=1.6.0.0
BUILDLINK_PKGSRCDIR.jdk16?=	../../wip/jdk16
BUILDLINK_JAVA_PREFIX.jdk16=	${PREFIX}/java/jdk-1.6.0

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.jdk16}

BUILDLINK_CPPFLAGS.jdk16= \
	-I${BUILDLINK_JAVA_PREFIX.jdk16}/include	\
	-I${BUILDLINK_JAVA_PREFIX.jdk16}/include/netbsd

.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif # JDK16_BUILDLINK3_MK

BUILDLINK_TREE+=	-jdk16
