# $NetBSD: buildlink3.mk,v 1.5 2010/07/04 16:38:10 hftmarkand Exp $

BUILDLINK_TREE+=	ode

.if !defined(ODE_BUILDLINK3_MK)
ODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ode+=	ode>=0.11.1
BUILDLINK_ABI_DEPENDS.ode+=	ode>=0.7
BUILDLINK_PKGSRCDIR.ode?=	../../wip/ode
.endif # ODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ode
