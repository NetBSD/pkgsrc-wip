# $NetBSD: buildlink3.mk,v 1.1 2004/02/25 13:29:25 johnrshannon Exp $
#
# This Makefile fragment is included by packages that use libgcrypt.
#
# This file was created automatically using createbuildlink-3.1.
#
BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH}+
LIBGCRYPT_BUILDLINK3_MK:=   ${LIBGCRYPT_BUILDLINK3_MK}+
 
.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=   libgcrypt
.endif
 
.if !empty(LIBGCRYPT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgcrypt?=       libgcrypt>=1.1.92
BUILDLINK_RECOMMENDED.libgcrypt?=   libgcrypt>=1.1.92
BUILDLINK_PKGSRCDIR.libgcrypt?=     ../../wip/libgcrypt
BUILDLINK_PACKAGES+=          libgcrypt
 
.  include "../libgpg-error/buildlink3.mk"
.endif # LIBGCRYPT_BUILDLINK3_MK
 
BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

