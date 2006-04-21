# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/21 04:18:46 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXKBUI_BUILDLINK3_MK:=	${LIBXKBUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxkbui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxkbui}
BUILDLINK_PACKAGES+=	libxkbui

.if !empty(LIBXKBUI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libxkbui+=	libxkbui>=1.0.1
BUILDLINK_PKGSRCDIR.libxkbui?=	../../wip/libxkbui
.endif	# LIBXKBUI_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../wip/libX11/buildlink3.mk"
#.include "../../wip/libXt/buildlink3.mk"
#.include "../../wip/libxkbfile/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
