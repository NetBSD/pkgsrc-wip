# $NetBSD: buildlink3.mk,v 1.4 2004/02/25 13:29:25 johnrshannon Exp $
#
# This Makefile fragment is included by packages that use libgpg-error.
#
BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH}+
LIBGPG_ERROR_BUILDLINK3_MK:=   ${LIBGPG_ERROR_BUILDLINK3_MK}+
 
.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=   libgpg-error
.endif
 
.if !empty(LIBGPG_ERROR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgpg-error?=       libgpg-error>=0.6
BUILDLINK_RECOMMENDED.libgpg-error?=   libgpg-error>=0.6
BUILDLINK_PKGSRCDIR.libgpg-error?=     ../../wip/libgpg-error
BUILDLINK_PACKAGES+=          libgpg-error
.endif # LIBGPG_ERROR_BUILDLINK3_MK
 
BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
