# $NetBSD: buildlink3.mk,v 1.1 2004/02/25 13:29:25 johnrshannon Exp $
#
# This Makefile fragment is included by packages that use libgassuan.
#
# This file was created automatically using createbuildlink-3.1.
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
 
.  include "../libgpg-error/buildlink3.mk"
.endif # LIBASSUAN_BUILDLINK3_MK
 
BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

