# $NetBSD$

BUILDLINK_TREE+=	sblim-sfcc

.if !defined(SBLIM_SFCC_BUILDLINK3_MK)
SBLIM_SFCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sblim-sfcc+=	sblim-sfcc>=2.2.8
BUILDLINK_PKGSRCDIR.sblim-sfcc?=	../../wip/sblim-sfcc

#.include "../../www/curl/buildlink3.mk"
.endif	# SBLIM_SFCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-sblim-sfcc
