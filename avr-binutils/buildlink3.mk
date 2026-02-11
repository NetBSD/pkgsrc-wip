# $NetBSD: buildlink3.mk,v 1.7 2024/04/26 11:48:09 micha Exp $

BUILDLINK_TREE+=	avr-binutils

.if !defined(AVR_BINUTILS_BUILDLINK3_MK)
AVR_BINUTILS_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++11

BUILDLINK_API_DEPENDS.avr-binutils+=		avr-binutils>=2.45
BUILDLINK_PKGSRCDIR.avr-binutils?=		../../wip/avr-binutils

.endif # AVR_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-binutils
