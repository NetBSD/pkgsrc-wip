# $NetBSD$

BUILDLINK_TREE+=	rust-bin

.if !defined(RUST_BUILDLINK3_MK)
RUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust-bin+=	rust-bin>=1.29.1
BUILDLINK_PKGSRCDIR.rust-bin?=		../../wip/rust-bin
BUILDLINK_DEPMETHOD.rust-bin?=		build

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/lib/rustlib
.endif

BUILDLINK_TREE+=	-rust-bin
