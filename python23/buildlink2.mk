# $NetBSD: buildlink2.mk,v 1.2 2003/07/31 15:15:35 marc Exp $

.if !defined(PYTHON23_BUILDLINK2_MK)
PYTHON23_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python23
BUILDLINK_PKGBASE.python23?=	python23
BUILDLINK_DEPENDS.python23?=	python23>=2.3
BUILDLINK_PKGSRCDIR.python23?=	../../wip/python23

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python23?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python23=python23
BUILDLINK_PREFIX.python23_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES_CMD.python23= \
	${BUILDLINK_PLIST_CMD.python23} |				\
		${GREP} '^\(include\|lib/libpython2\.3.*\)'
BUILDLINK_TRANSFORM+=		l:python:python23

BUILDLINK_CPPFLAGS.python23+= \
	-I${BUILDLINK_PREFIX.python23}/include/python23

BUILDLINK_TARGETS+=	python23-buildlink

python23-buildlink: _BUILDLINK_USE

.endif	# PYTHON23_BUILDLINK2_MK
