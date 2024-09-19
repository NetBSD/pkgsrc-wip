# $NetBSD: buildlink3.mk,v 1.1 2015/08/02 05:28:52 devnexen Exp $

BUILDLINK_TREE+=	deviceatlas-enterprise-c

.if !defined(DEVICEATLAS_ENTERPRISE_C_BUILDLINK3_MK)
DEVICEATLAS_ENTERPRISE_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deviceatlas-enterprise-c+=	pcre>=0.9nb1
BUILDLINK_PKGSRCDIR.deviceatlas-enterprise-c?=		../../wip/deviceatlas-enterprise-c
.endif # DEVICEATLAS_ENTERPRISE_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-deviceatlas-enterprise-c
