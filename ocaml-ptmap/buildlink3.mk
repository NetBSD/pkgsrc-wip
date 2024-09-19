# $NetBSD$

BUILDLINK_TREE+=	ocaml-ptmap

.if !defined(OCAML_PTMAP_BUILDLINK3_MK)
OCAML_PTMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ptmap+=	ocaml-ptmap>=2.0.4
BUILDLINK_PKGSRCDIR.ocaml-ptmap?=	../../wip/ocaml-ptmap

.endif	# OCAML_PTMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ptmap
