# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:47:33 cheusov Exp $

BUILDLINK_TREE+=	rte

.if !defined(RTE_BUILDLINK3_MK)
RTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rte+=	rte>=0.5.6
BUILDLINK_PKGSRCDIR.rte?=	../../wip/rte

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # RTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-rte
