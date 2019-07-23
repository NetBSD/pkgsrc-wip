# $NetBSD: buildlink3.mk,v 1.21 2016/03/18 09:36:26 wiz Exp $

BUILDLINK_TREE+=			compat32_expat

.if !defined(COMPAT32_EXPAT_BUILDLINK3_MK)
COMPAT32_EXPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_expat+=	compat32_expat>=1.95.7
BUILDLINK_ABI_DEPENDS.compat32_expat+=	compat32_expat>=2.0.0nb1
BUILDLINK_PKGSRCDIR.compat32_expat?=	../../wip/compat32_expat
BUILDLINK_LIBDIRS.compat32_expat=	emul/netbsd32/lib
BUILDLINK_INCDIRS.compat32_expat=	emul/netbsd32/include
.endif # COMPAT32_EXPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_expat
