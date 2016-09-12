# $NetBSD$

BUILDLINK_TREE+=	polly

.if !defined(POLLY_BUILDLINK3_MK)
POLLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polly+=	polly>=3.8.1
BUILDLINK_PKGSRCDIR.polly?=	../../wip/polly

.include "../../lang/llvm/buildlink3.mk"
.endif	# POLLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-polly
