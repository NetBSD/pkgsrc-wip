# $NetBSD: buildlink2.mk,v 1.3 2004/04/27 15:31:51 thomasklausner Exp $

.if !defined(JDK13_BUILDLINK2_MK)
JDK13_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		jdk13
BUILDLINK_PKGBASE.jdk13?=	jdk13
BUILDLINK_DEPENDS.jdk13?=	jdk13-[0-9]*
BUILDLINK_PKGSRCDIR.jdk13?=	../../lang/jdk13

BUILDLINK_PREFIX.jdk13=	${LOCALBASE}
BUILDLINK_FILES_CMD.jdk13= \
	${BUILDLINK_PLIST_CMD.jdk13} |					\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

EVAL_PREFIX+=	BUILDLINK_JAVA_PREFIX.jdk13=jdk13
BUILDLINK_JAVA_PREFIX.jdk13_DEFAULT= \
	${BUILDLINK_PREFIX.jdk13}/java/jdk-1.3.1

BUILDLINK_CPPFLAGS.jdk13= \
	-I${BUILDLINK_JAVA_PREFIX.jdk13}/include				\
	-I${BUILDLINK_JAVA_PREFIX.jdk13}/include/netbsd

BUILDLINK_TARGETS+=	jdk13-buildlink

jdk13-buildlink: _BUILDLINK_USE

.endif	# JDK13_BUILDLINK2_MK
