# $NetBSD: buildlink2.mk,v 1.3 2004/04/27 15:31:50 thomasklausner Exp $

.if !defined(JDK12_BUILDLINK2_MK)
JDK12_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		jdk12
BUILDLINK_PKGBASE.jdk12?=	jdk12
BUILDLINK_DEPENDS.jdk12?=	jdk12-[0-9]*
BUILDLINK_PKGSRCDIR.jdk12?=	../../lang/jdk12

BUILDLINK_PREFIX.jdk12=	${LOCALBASE}
BUILDLINK_FILES_CMD.jdk12= \
	${BUILDLINK_PLIST_CMD.jdk12} |					\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

EVAL_PREFIX+=	BUILDLINK_JAVA_PREFIX.jdk12=jdk12
BUILDLINK_JAVA_PREFIX.jdk12_DEFAULT= \
	${BUILDLINK_PREFIX.jdk12}/java/jdk-1.2.2

BUILDLINK_CPPFLAGS.jdk12= \
	-I${BUILDLINK_JAVA_PREFIX.jdk12}/include				\
	-I${BUILDLINK_JAVA_PREFIX.jdk12}/include/netbsd

BUILDLINK_TARGETS+=	jdk12-buildlink

jdk12-buildlink: _BUILDLINK_USE

.endif	# JDK12_BUILDLINK2_MK
