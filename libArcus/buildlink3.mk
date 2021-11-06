# $NetBSD$

BUILDLINK_TREE+=	libArcus

.if !defined(LIBARCUS_BUILDLINK3_MK)
LIBARCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libArcus+=	libArcus>=4.11.0
BUILDLINK_PKGSRCDIR.libArcus?=		../../wip/libArcus

.include "../../lang/python/extension.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.endif	# LIBARCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libArcus
