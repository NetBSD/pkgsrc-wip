# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	p5-Quota

BUILDLINK_API_DEPENDS.p5-Quota+=	p5-Quota>=1.5.1
BUILDLINK_PKGSRCDIR.p5-Quota?=	../../wip/p5-Quota

.include "../../lang/perl5/buildlink3.mk"
.endif # P5_QUOTA_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-Quota
