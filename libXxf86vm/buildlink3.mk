# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/21 04:15:42 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXXF86VM_BUILDLINK3_MK:=	${LIBXXF86VM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXxf86vm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXxf86vm}
BUILDLINK_PACKAGES+=	libXxf86vm

.if !empty(LIBXXF86VM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libXxf86vm+=	libXxf86vm>=1.0.0
BUILDLINK_PKGSRCDIR.libXxf86vm?=	../../wip/libXxf86vm
.endif	# LIBXXF86VM_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../x11/xproto/buildlink3.mk"
#.include "../../wip/libX11/buildlink3.mk"
#.include "../../x11/xextproto/buildlink3.mk"
#.include "../../wip/xf86vidmodeproto/buildlink3.mk"
#.include "../../wip/libXext/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
