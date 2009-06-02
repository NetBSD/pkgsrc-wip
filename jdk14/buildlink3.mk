# $NetBSD: buildlink3.mk,v 1.8 2009/06/02 13:25:58 noud4 Exp $

BUILDLINK_TREE+=	jdk14

.if !defined(JDK14_BUILDLINK3_MK)
JDK14_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jdk14+=	jdk14>=1.4.2.6
BUILDLINK_PKGSRCDIR.jdk14?=	../../wip/jdk14
BUILDLINK_JAVA_PREFIX.jdk14=	${PREFIX}/java/jdk-1.4.2

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_JAVA_PREFIX.jdk14}

BUILDLINK_CPPFLAGS.jdk14= \
	-I${BUILDLINK_JAVA_PREFIX.jdk14}/include				\
	-I${BUILDLINK_JAVA_PREFIX.jdk14}/include/netbsd

.if ${X11_TYPE} == "modular"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.else
.include "../../mk/x11.buildlink3.mk"
.endif # X11_TYPE
.endif # JDK14_BUILDLINK3_MK

BUILDLINK_TREE+=	-jdk14
