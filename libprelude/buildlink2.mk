# $NetBSD: buildlink2.mk,v 1.3 2004/02/07 14:15:41 adrian_p Exp $

BUILDLINK_PACKAGES+=			libprelude
BUILDLINK_PKGBASE.libprelude+=		libprelude
BUILDLINK_DEPENDS.libprelude?=		libprelude>=0.8.10
BUILDLINK_PKGSRCDIR.libprelude?=	../../wip/libprelude

EVAL_PREFIX+=				BUILDLINK_PREFIX.libprelude=libprelude
BUILDLINK_PREFIX.libprelude_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libprelude=		include/libprelude/*.h
BUILDLINK_FILES.libprelude+=		lib/libprelude.*

BUILDLINK_TARGETS+=	libprelude-buildlink

libprelude-buildlink: _BUILDLINK_USE
