# $NetBSD: buildlink3.mk,v 1.3 2004/06/13 19:07:49 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libXau.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXAU_BUILDLINK3_MK:=	${LIBXAU_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libXau
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXau}
BUILDLINK_PACKAGES+=	libXau

.if !empty(LIBXAU_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libXau?=		libXau>=0.1
BUILDLINK_PKGSRCDIR.libXau?=		../../wip/libXau
.endif # LIBXAU_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
