# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/03/03 22:38:45 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use com_err.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(COM_ERR_BUILDLINK2_MK)
COM_ERR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			com_err
BUILDLINK_DEPENDS.com_err?=		com_err>=1.35
BUILDLINK_PKGSRCDIR.com_err?=		../../wip/com_err

EVAL_PREFIX+=	BUILDLINK_PREFIX.com_err=com_err
BUILDLINK_PREFIX.com_err_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.com_err+=	include/et/com_err.h
BUILDLINK_FILES.com_err+=	lib/libcom_err.*

BUILDLINK_TARGETS+=	com_err-buildlink

com_err-buildlink: _BUILDLINK_USE

.endif	# COM_ERR_BUILDLINK2_MK
