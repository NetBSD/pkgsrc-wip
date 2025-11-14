# $NetBSD: buildlink3.mk,v 1.6 2019/12/29 15:31:21 adam Exp $

BUILDLINK_TREE+=	polly

.if !defined(POLLY_BUILDLINK3_MK)
POLLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polly+=	polly>=21.1.0
BUILDLINK_PKGSRCDIR.polly?=	../../wip/polly

.include "../../wip/llvm/buildlink3.mk"
.endif	# POLLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-polly
