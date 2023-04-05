# $NetBSD$

BUILDLINK_TREE+=	gcc10-libjit

.if !defined(GCC10_LIBJIT_BUILDLINK3_MK)
GCC10_LIBJIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc10-libjit+=	gcc10-libjit>=10.4.0
BUILDLINK_PKGSRCDIR.gcc10-libjit?=	../../wip/gcc10-libjit

BUILDLINK_PASSTHRU_DIRS+=			${BUILDLINK_PREFIX.gcc10-libjit}/gcc10
BUILDLINK_FNAME_TRANSFORM.gcc10-libjit+=	-e s,gcc10/lib,lib,
BUILDLINK_FNAME_TRANSFORM.gcc10-libjit+=	-e s,gcc10/include,include,
.endif	# GCC10_LIBJIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc10-libjit
