BUILDLINK_TREE+=	ocaml-sexplib

.if !defined(OCAML_SEXPLIB_BUILDLINK3_MK)
OCAML_SEXPLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-sexplib+=	ocaml-sexplib>=112.01.00
BUILDLINK_PKGSRCDIR.ocaml-sexplib?=	../../wip/ocaml-sexplib

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAML_SEXPLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-sexplib
