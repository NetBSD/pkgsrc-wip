# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/22 12:13:17 marc Exp $

.if !defined(SUN_JRE14_BUILDLINK2_MK)
SUN_JRE14_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sun-jre142
BUILDLINK_PKGBASE.sun-jre142?=	sun-jre142
BUILDLINK_DEPENDS.sun-jre142?=	sun-jre142-[0-9]*
BUILDLINK_PKGSRCDIR.sun-jre142?=	../../wip/sun-jre142

BUILDLINK_PREFIX.sun-jre142=	${LOCALBASE}
BUILDLINK_FILES_CMD.sun-jre142= \
	${BUILDLINK_PLIST_CMD.sun-jre142} |				\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

EVAL_PREFIX+=	BUILDLINK_JAVA_PREFIX.sun-jre142=sun-jre142
BUILDLINK_JAVA_PREFIX.sun-jre142_DEFAULT= \
	${BUILDLINK_PREFIX.sun-jre142}/java/sun-1.4.2

UNLIMIT_RESOURCES+=	datasize	# must be at least 131204
BUILDLINK_TARGETS+=	sun-jre142-buildlink

sun-jre142-buildlink: _BUILDLINK_USE

.endif	# SUN_JRE14_BUILDLINK2_MK
