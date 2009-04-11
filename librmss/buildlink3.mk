# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/04/11 12:57:45 jihbed Exp $

BUILDLINK_TREE+=	libmrss

.if !defined(LIBMRSS_BUILDLINK3_MK)
LIBMRSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmrss+=	libmrss>=0.19.2
BUILDLINK_PKGSRCDIR.libmrss?=	../../wip/librmss


.include "../../wip/libnxml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBMRSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmrss
