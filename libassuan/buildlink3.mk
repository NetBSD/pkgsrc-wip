# $NetBSD: buildlink3.mk,v 1.2 2004/02/26 03:08:16 minskim Exp $
#
# This Makefile fragment is included by packages that use libgassuan.
#
BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH}+
LIBASSUAN_BUILDLINK3_MK:=   ${LIBASSUAN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=   libassuan
.endif

.if !empty(LIBASSUAN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libassuan?=       libassuan>=0.6.4
BUILDLINK_RECOMMENDED.libassuan?=   libassuan>=0.6.4
BUILDLINK_PKGSRCDIR.libassuan?=     ../../wip/libassuan
BUILDLINK_PACKAGES+=          libassuan

.  include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBASSUAN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
