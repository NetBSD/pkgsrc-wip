# $NetBSD$

BUILDLINK_TREE+=	gtk-layer-shell

.if !defined(GTK_LAYER_SHELL_BUILDLINK3_MK)
GTK_LAYER_SHELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-layer-shell+=	gtk-layer-shell>=0.10.0
BUILDLINK_ABI_DEPENDS.gtk-layer-shell+=	gtk-layer-shell>=0.10.0
BUILDLINK_PKGSRCDIR.gtk-layer-shell?=	../../wip/gtk-layer-shell

.endif # GTK_LAYER_SHELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-layer-shell
