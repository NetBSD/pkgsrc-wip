# $NetBSD: buildlink2.mk,v 1.1 2004/01/24 19:59:53 oherrala Exp $
#

.if !defined(SILC_TOOLKIT_BUILDLINK2_MK)
SILC_TOOLKIT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			silc-toolkit
BUILDLINK_DEPENDS.silc-toolkit?=	silc-toolkit>=0.9.11
BUILDLINK_PKGSRCDIR.silc-toolkit?=	../../wip/silc-toolkit

EVAL_PREFIX+=	BUILDLINK_PREFIX.silc-toolkit=silc-toolkit
BUILDLINK_PREFIX.silc-toolkit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.silc-toolkit+=	include/silc-toolkit/*.h
BUILDLINK_FILES.silc-toolkit+=	lib/silc-toolkit/libsilc-1.0.*
BUILDLINK_FILES.silc-toolkit+=	lib/silc-toolkit/libsilc.*
BUILDLINK_FILES.silc-toolkit+=	lib/silc-toolkit/libsilcclient-1.0.*
BUILDLINK_FILES.silc-toolkit+=	lib/silc-toolkit/libsilcclient.*

.include "../../converters/libiconv/buildlink2.mk"

BUILDLINK_TARGETS+=	silc-toolkit-buildlink

silc-toolkit-buildlink: _BUILDLINK_USE

.endif	# SILC_TOOLKIT_BUILDLINK2_MK
