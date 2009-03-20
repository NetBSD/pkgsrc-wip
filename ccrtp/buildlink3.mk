# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	ccrtp

.if !defined(CCRTP_BUILDLINK3_MK)
CCRTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ccrtp+=	ccrtp>=1.5.0
BUILDLINK_PKGSRCDIR.ccrtp?=	../../wip/ccrtp

.include "../../wip/commoncpp2/buildlink3.mk"
.endif # CCRTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ccrtp
