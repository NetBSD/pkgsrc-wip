# $NetBSD: buildlink3.mk,v 1.2 2014/06/18 05:08:59 makoto Exp $

BUILDLINK_TREE+=	avr-gcc

.if !defined(AVR_GCC_BUILDLINK3_MK)
AVR_GCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avr-gcc+=		avr-gcc>=4.8.3
BUILDLINK_PKGSRCDIR.avr-gcc?=		../../wip/avr-gcc
BUILDLINK_FNAME_TRANSFORM.avr-gcc+=	-e "s,${AVR_TARGET}/lib/,lib/,g"

.endif # AVR_GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-gcc
