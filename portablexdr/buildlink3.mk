# $NetBSD$

BUILDLINK_TREE+=	portablexdr

.if !defined(PORTABLEXDR_BUILDLINK3_MK)
PORTABLEXDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.portablexdr+=	portablexdr>=4.9.1
BUILDLINK_PKGSRCDIR.portablexdr?=	../../wip/portablexdr
.endif

BUILDLINK_TREE+=	-portablexdr
