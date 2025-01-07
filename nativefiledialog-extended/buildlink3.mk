# $NetBSD: buildlink3.mk,v 1.1 2024/10/09 14:05:56 ktnb Exp $

BUILDLINK_TREE+=	nativefiledialog-extended

.if !defined(NATIVEFILEDIALOG_EXTENDED_BUILDLINK3_MK)
NATIVEFILEDIALOG_EXTENDED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nativefiledialog-extended+=	nativefiledialog-extended>=1.2.1
BUILDLINK_PKGSRCDIR.nativefiledialog-extended?=		../../wip/nativefiledialog-extended

.endif	# NATIVEFILEDIALOG_EXTENDED_BUILDLINK3_MK

BUILDLINK_TREE+=	-nativefiledialog-extended
