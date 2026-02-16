# $NetBSD$

BUILDLINK_TREE+=	gtk4-layer-shell

.if !defined(GTK4_LAYER_SHELL_BUILDLINK3_MK)
GTK4_LAYER_SHELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk4-layer-shell+=	gtk4-layer-shell>=1.3.0
BUILDLINK_ABI_DEPENDS.gtk4-layer-shell+=	gtk4-layer-shell>=1.3.0
BUILDLINK_PKGSRCDIR.gtk4-layer-shell?=		../../wip/gtk4-layer-shell

.endif # GTK4_LAYER_SHELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk4-layer-shell
