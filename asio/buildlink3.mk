# $NetBSD: buildlink3.mk,v 1.1 2014/12/25 12:12:49 nros Exp $
#

BUILDLINK_TREE+=	asio

.if !defined(ASIO_BUILDLINK3_MK)
ASIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.asio+=	asio>=1.10.4
BUILDLINK_PKGSRCDIR.asio?=	../../wip/asio
BUILDLINK_DEPMETHOD.asio?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# ASIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-asio
