# $NetBSD: buildlink3.mk,v 1.6 2011/10/29 11:18:56 othyro Exp $

BUILDLINK_TREE+=	ccrtp

.if !defined(CCRTP_BUILDLINK3_MK)
CCRTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ccrtp+=	ccrtp>=2.0.0
BUILDLINK_PKGSRCDIR.ccrtp?=	../../wip/ccrtp

.include "../../wip/ucommon/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.endif # CCRTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ccrtp
