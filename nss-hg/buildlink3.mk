# $NetBSD: buildlink3.mk,v 1.1 2014/09/28 14:20:08 thomasklausner Exp $

BUILDLINK_TREE+=	nss

.if !defined(NSS_BUILDLINK3_MK)
NSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nss+=	nss>=3.25
BUILDLINK_PKGSRCDIR.nss?=	../../wip/nss-hg

BUILDLINK_LIBDIRS.nss+=		lib/nss
BUILDLINK_RPATHDIRS.nss+=	lib/nss

BUILDLINK_INCDIRS.nss+=		include/nss/nss

.include "../../wip/nspr-hg/buildlink3.mk"
.endif # NSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nss
