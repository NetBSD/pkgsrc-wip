# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/28 10:49:28 jihbed Exp $

BUILDLINK_TREE+=	ta-lib

.if !defined(TA_LIB_BUILDLINK3_MK)
TA_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ta-lib+=	ta-lib>=0.4.0
BUILDLINK_PKGSRCDIR.ta-lib?=	../../wip/ta-lib
.endif	# TA_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ta-lib
