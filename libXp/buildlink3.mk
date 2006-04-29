# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/29 04:27:30 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXP_BUILDLINK3_MK:=	${LIBXP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXp}
BUILDLINK_PACKAGES+=	libXp

.if !empty(LIBXP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libXp+=	libXp>=1.0.0
BUILDLINK_PKGSRCDIR.libXp?=	../../wip/libXp
.endif	# LIBXP_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../wip/libX11/buildlink3.mk"
#.include "../../wip/libXext/buildlink3.mk"
#.include "../../x11/xextproto/buildlink3.mk"
#.include "../../wip/printproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
