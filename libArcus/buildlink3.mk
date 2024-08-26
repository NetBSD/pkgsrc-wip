# $NetBSD$

BUILDLINK_TREE+=	libArcus

.if !defined(LIBARCUS_BUILDLINK3_MK)
LIBARCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libArcus+=	libArcus>=4.11.0
BUILDLINK_PKGSRCDIR.libArcus?=		../../wip/libArcus

BUILDLINK_DEPMETHOD.py-sip4?=	build

.include "../../lang/python/extension.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../wip/py-sip4/buildlink3.mk"
.endif	# LIBARCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libArcus
