# $NetBSD: buildlink3.mk,v 1.1 2012/02/07 03:22:47 makoto Exp $

BUILDLINK_TREE+=	avr-gcc

.if !defined(AVR_GCC_BUILDLINK3_MK)
AVR_GCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avr-gcc+=		avr-gcc>=4.5.3
BUILDLINK_PKGSRCDIR.avr-gcc?=		../../wip/avr-gcc
BUILDLINK_FNAME_TRANSFORM.avr-gcc+=	-e "s,${AVR_TARGET}/lib,lib/,g"

.include "../../wip/avr-binutils/buildlink3.mk"
.endif # AVR_GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-gcc
