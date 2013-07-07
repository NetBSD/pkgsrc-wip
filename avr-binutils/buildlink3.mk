# $NetBSD: buildlink3.mk,v 1.3 2013/07/07 04:36:16 makoto Exp $

BUILDLINK_TREE+=	avr-binutils

.if !defined(AVR_BINUTILS_BUILDLINK3_MK)
AVR_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avr-binutils+=	avr-binutils>=2.22
BUILDLINK_PKGSRCDIR.avr-binutils?=		../../wip/avr-binutils
#BUILDLINK_FNAME_TRANSFORM.avr-binutils+=	-e "s,${AVR_TARGET}/lib,lib/,g"

.endif # AVR_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-binutils
