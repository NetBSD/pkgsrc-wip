# $NetBSD: buildlink3.mk,v 1.18 2023/01/11 23:18:25 nikita Exp $

BUILDLINK_TREE+=	zig-git

.if !defined(ZIG_GIT_BUILDLINK3_MK)
ZIG_GIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zig-git+=	zig-git>=0.11.0
BUILDLINK_ABI_DEPENDS.zig-git+=	zig-git>=0.11.0
BUILDLINK_PKGSRCDIR.zig-git?=	../../wip/zig-git

pkgbase := zig-git

.endif # ZIG_GIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-zig-git
