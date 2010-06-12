# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/06/12 23:18:56 jihbed Exp $

BUILDLINK_TREE+=	liboauth

.if !defined(LIBOAUTH_BUILDLINK3_MK)
LIBOAUTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboauth+=	liboauth>=0.8.8
BUILDLINK_PKGSRCDIR.liboauth?=	../../wip/liboauth


.include "../../devel/nss/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBOAUTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboauth
