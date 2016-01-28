# $NetBSD$

BUILDLINK_TREE+=	p11-kit

.if !defined(P11_KIT_BUILDLINK3_MK)
P11_KIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p11-kit+=	p11-kit>=0.23.2
BUILDLINK_PKGSRCDIR.p11-kit?=	../../wip/p11-kit

#.include "../../security/libtasn1/buildlink3.mk"
#.include "../../devel/libffi/buildlink3.mk"
.endif	# P11_KIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-p11-kit
