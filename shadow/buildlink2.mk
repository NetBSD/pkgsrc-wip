# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/04 00:20:47 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use shadow.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(SHADOW_BUILDLINK2_MK)
SHADOW_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			shadow
BUILDLINK_DEPENDS.shadow?=		shadow>=4.0.3nb2
BUILDLINK_PKGSRCDIR.shadow?=		../../wip/shadow

EVAL_PREFIX+=	BUILDLINK_PREFIX.shadow=shadow
BUILDLINK_PREFIX.shadow_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.shadow+=	lib/libmisc.*
BUILDLINK_FILES.shadow+=	lib/libshadow.*

.include "../../security/linux-pam/buildlink2.mk"

BUILDLINK_TARGETS+=	shadow-buildlink

shadow-buildlink: _BUILDLINK_USE

.endif	# SHADOW_BUILDLINK2_MK
