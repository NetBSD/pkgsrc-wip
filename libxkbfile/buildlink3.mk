# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/11/10 03:50:42 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXKBFILE_BUILDLINK3_MK:=	${LIBXKBFILE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxkbfile
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxkbfile}
BUILDLINK_PACKAGES+=	libxkbfile

.if !empty(LIBXKBFILE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxkbfile+=	libxkbfile>=0.99.1
BUILDLINK_PKGSRCDIR.libxkbfile?=	../../wip/libxkbfile
.endif	# LIBXKBFILE_BUILDLINK3_MK

.include "../../wip/kbproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
