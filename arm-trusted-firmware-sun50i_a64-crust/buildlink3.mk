# $NetBSD: buildlink3.mk,v 1.3 2019/02/27 06:23:39 martin Exp $

BUILDLINK_DEPMETHOD.arm-trusted-firmware-sun50i_a64-crust?=	build

BUILDLINK_TREE+=	arm-trusted-firmware-sun50i_a64-crust

.if !defined(ARM_TRUSTED_FIRMWARE_SUN50I_A64_CRUST_BUILDLINK3_MK)
ARM_TRUSTED_FIRMWARE_SUN50I_A64_CRUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arm-trusted-firmware-sun50i_a64-crust+=	arm-trusted-firmware-sun50i_a64-crust>2.0
BUILDLINK_PKGSRCDIR.arm-trusted-firmware-sun50i_a64-crust?=	../../wip/arm-trusted-firmware-sun50i_a64-crust
.endif	# ARM_TRUSTED_FIRMWARE_SUN50I_A64_CRUST_BUILDLINK3_MK

BUILDLINK_TREE+=	-arm-trusted-firmware-sun50i_a64-crust

