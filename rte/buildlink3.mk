# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:52 jsonn Exp $

BUILDLINK_TREE+=	rte

BUILDLINK_API_DEPENDS.rte+=		rte>=0.5.6
BUILDLINK_PKGSRCDIR.rte?=	../../wip/rte

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # RTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-rte
