# $NetBSD: buildlink3.mk,v 1.12 2016/03/05 11:27:46 jperkin Exp $

BUILDLINK_TREE+=	opal

.if !defined(OPAL_BUILDLINK3_MK)
OPAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opal+=	opal>=3.6.1
BUILDLINK_ABI_DEPENDS.opal+=	opal>=3.6.6nb12
BUILDLINK_PKGSRCDIR.opal?=	../../wip/opal

.include "../../audio/speex/buildlink3.mk"
.include "../../wip/ptlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-opal
