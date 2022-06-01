# $NetBSD$

BUILDLINK_TREE+=	avr-gcc

.if !defined(AVR_GCC_BUILDLINK3_MK)
AVR_GCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avr-gcc+=	avr-gcc>=12.1.0
BUILDLINK_PKGSRCDIR.avr-gcc?=	../../wip/avr-gcc
.endif	# AVR_GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-gcc
