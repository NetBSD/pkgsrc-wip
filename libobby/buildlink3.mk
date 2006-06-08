# $NetBSD: buildlink3.mk,v 1.4 2006/06/08 11:14:27 absd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBOBBY_BUILDLINK3_MK:=	${LIBOBBY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libobby
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibobby}
BUILDLINK_PACKAGES+=	libobby

.if !empty(LIBOBBY_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libobby+=	libobby>=0.2.0
BUILDLINK_PKGSRCDIR.libobby?=	../../wip/libobby
.endif	# LIBOBBY_BUILDLINK3_MK

.include "../../wip/net6/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
