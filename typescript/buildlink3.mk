# $NetBSD$

BUILDLINK_TREE+=	typescript

.if !defined(TYPESCRIPT_BUILDLINK3_MK)
TYPESCRIPT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.typescript?=	build

BUILDLINK_API_DEPENDS.typescript+=	typescript>=6.0.3
BUILDLINK_PKGSRCDIR.typescript?=	../../wip/typescript
#BUILDLINK_PKGSRCDIR.typescript?=	../../lang/typescript
.endif	# TYPESCRIPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-typescript
