# $NetBSD: buildlink3.mk,v 1.1 2004/02/25 13:29:25 johnrshannon Exp $
#
# This Makefile fragment is included by packages that use libgcrypt.
#
# This file was created automatically using createbuildlink-3.1.
#
BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH}+
LIBKSBA_BUILDLINK3_MK:=   ${LIBKSBA_BUILDLINK3_MK}+
 
.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=   libksba
.endif
 
.if !empty(LIBKSBA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libksba?=       libksba>=0.9.4
BUILDLINK_RECOMMENDED.libksba?=   libksba>=0.9.4
BUILDLINK_PKGSRCDIR.libksba?=     ../../wip/libksba
BUILDLINK_PACKAGES+=          libksba
 
.  include "../libgcrypt/buildlink3.mk"
.  include "../libassuan/buildlink3.mk"
.  include "../libgpg-error/buildlink3.mk"
.endif # LIBKSBA_BUILDLINK3_MK
 
BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

