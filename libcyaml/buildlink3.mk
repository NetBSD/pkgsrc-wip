# $NetBSD$

BUILDLINK_TREE+=	libcyaml

.if !defined(LIBCYAML_BUILDLINK3_MK)
LIBCYAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcyaml+=	libcyaml>=1.1.0
BUILDLINK_ABI_DEPENDS.libcyaml+=	libcyaml>=1.1.0
BUILDLINK_PKGSRCDIR.libcyaml?=		../../wip/libcyaml
.endif # LIBCYAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcyaml
