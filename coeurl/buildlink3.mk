# $NetBSD$

BUILDLINK_TREE+=	coeurl

.if !defined(COEURL_BUILDLINK3_MK)
COEURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.coeurl+=	coeurl>=0.3.1
BUILDLINK_PKGSRCDIR.coeurl?=	../../wip/coeurl

.include "../../www/curl/buildlink3.mk"
.endif	# COEURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-coeurl
