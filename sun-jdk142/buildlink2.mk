# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/22 12:21:11 marc Exp $

.if !defined(SUN_JDK14_BUILDLINK2_MK)
SUN_JDK14_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sun-jdk142
BUILDLINK_PKGBASE.sun-jdk142?=	sun-jdk142
BUILDLINK_DEPENDS.sun-jdk142?=	sun-jdk142-[0-9]*
BUILDLINK_PKGSRCDIR.sun-jdk142?=	../../wip/sun-jdk142
BUILDLINK_DEPMETHOD.sun-jdk142?=	build

BUILDLINK_PREFIX.sun-jdk142=	${LOCALBASE}
BUILDLINK_FILES_CMD.sun-jdk142= \
	${BUILDLINK_PLIST_CMD.sun-jdk142} |				\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

BUILDLINK_CPPFLAGS.sun-jdk142= \
	-I${BUILDLINK_JAVA_PREFIX.sun-jre142}/include			\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre142}/include/linux

.include "../../wip/sun-jre142/buildlink2.mk"

BUILDLINK_TARGETS+=	sun-jdk142-buildlink

sun-jdk142-buildlink: _BUILDLINK_USE

.endif	# SUN_JDK14_BUILDLINK2_MK
