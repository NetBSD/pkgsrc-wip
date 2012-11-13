# $NetBSD: buildlink3.mk,v 1.1 2012/11/13 16:45:34 othyro Exp $

BUILDLINK_TREE+=	hawknl

.if !defined(HAWKNL_BUILDLINK3_MK)
HAWKNL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hawknl+=	hawknl>=1.7beta1
BUILDLINK_PKGSRCDIR.hawknl?=	../../wip/hawknl

.include "../../mk/pthread.buildlink3.mk"
.endif	# HAWKNL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hawknl
