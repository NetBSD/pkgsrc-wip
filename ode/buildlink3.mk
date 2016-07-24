# $NetBSD$

BUILDLINK_TREE+=	ode

.if !defined(ODE_BUILDLINK3_MK)
ODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ode+=	ode>=0.13
BUILDLINK_PKGSRCDIR.ode?=	../../wip/ode

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# ODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ode
