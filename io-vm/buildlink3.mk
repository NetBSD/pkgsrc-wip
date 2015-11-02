# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	io-vm

.if !defined(IOVM_BUILDLINK3_MK)
IOVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.io-vm+=		io-vm>=2013.12.04
BUILDLINK_PKGSRCDIR.io-vm?=		../../wip/io-vm

BUILDLINK_INCDIRS.io-vm+=		include/io
.endif # IOVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-io-vm
