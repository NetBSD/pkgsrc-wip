# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/03 11:59:26 adrian_p Exp $
#

BUILDLINK_PACKAGES+=		libol
BUILDLINK_PKGBASE.libol=	libol
BUILDLINK_DEPENDS.libol?=	libol>=0.3.11
BUILDLINK_PKGSRCDIR.libol?=	../../wip/libol

EVAL_PREFIX+=			BUILDLINK_PREFIX.libol=libol
BUILDLINK_PREFIX.libol_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libol=		include/libol/*.h
BUILDLINK_FILES.libol+=		include/libol/*.x
BUILDLINK_FILES.libol+=		lib/libol.*

BUILDLINK_TARGETS+=		libol-buildlink

libol-buildlink: _BUILDLINK_USE
