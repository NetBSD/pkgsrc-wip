# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/04 17:55:36 froz Exp $
#
# This Makefile fragment is included by packages that use shared-mime-info.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(SHARED_MIME_INFO_BUILDLINK2_MK)
SHARED_MIME_INFO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			shared-mime-info
BUILDLINK_DEPENDS.shared-mime-info?=	shared-mime-info>=0.12
BUILDLINK_PKGSRCDIR.shared-mime-info?=	../../wip/shared-mime-info

EVAL_PREFIX+=	BUILDLINK_PREFIX.shared-mime-info=shared-mime-info
BUILDLINK_PREFIX.shared-mime-info_DEFAULT=	${LOCALBASE}

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	shared-mime-info-buildlink

# Location of the update-mime-database binary program.
UPDATE_MIME_DATABASE=	${BUILDLINK_PREFIX.shared-mime-info}/bin/update-mime-database

shared-mime-info-buildlink: _BUILDLINK_USE

.endif	# SHARED_MIME_INFO_BUILDLINK2_MK
