# $NetBSD: buildlink3.mk,v 1.1 2015/02/26 10:51:30 jgoamakf Exp $
BUILDLINK_TREE+=	ocaml-custom_printf

.if !defined(OCAML_CUSTOM_PRINTF_BUILDLINK3_MK)
OCAML_CUSTOM_PRINTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-custom_printf+=	ocaml-custom_printf>=112.17.00
BUILDLINK_PKGSRCDIR.ocaml-custom_printf?=	../../wip/ocaml-custom_printf
.endif	# OCAML_CUSTOM_PRINTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-custom_printf
