# $NetBSD$

BUILDLINK_TREE+=	avr-binutils

.if !defined(AVR_BINUTILS_BUILDLINK3_MK)
AVR_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avr-binutils+=		avr-binutils>=2.37
BUILDLINK_ABI_DEPENDS.avr-binutils?=		avr-binutils>=2.42
BUILDLINK_PKGSRCDIR.avr-binutils?=		../../wip/avr-binutils

.endif # AVR_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-binutils
