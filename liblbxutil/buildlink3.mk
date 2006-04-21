# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/21 04:26:40 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBLBXUTIL_BUILDLINK3_MK:=	${LIBLBXUTIL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	liblbxutil
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nliblbxutil}
BUILDLINK_PACKAGES+=	liblbxutil

.if !empty(LIBLBXUTIL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.liblbxutil+=	liblbxutil>=1.0.0
BUILDLINK_PKGSRCDIR.liblbxutil?=	../../wip/liblbxutil
.endif	# LIBLBXUTIL_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../x11/xextproto/buildlink3.mk"
#.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
