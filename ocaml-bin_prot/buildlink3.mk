# $NetBSD: buildlink3.mk,v 1.1 2014/11/16 22:46:18 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-bin_prot

.if !defined(OCAML_BIN_PROT_BUILDLINK3_MK)
OCAML_BIN_PROT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-bin_prot+=	ocaml-bin_prot>=112.01.00
BUILDLINK_PKGSRCDIR.ocaml-bin_prot?=	../../wip/ocaml-bin_prot

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAML_BIN_PROT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-bin_prot
