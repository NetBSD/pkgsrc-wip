# $NetBSD$

BUILDLINK_TREE+=	nongnu-libunwind

.if !defined(NONGNU_LIBUNWIND_BUILDLINK3_MK)
NONGNU_LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nongnu-libunwind+=	non-libunwind>=1.1nb20151127
BUILDLINK_PKGSRCDIR.nongnu-libunwind?=		../../wip/nongnu-libunwind-git

.endif	# NONGNU_LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-nongnu-libunwind
