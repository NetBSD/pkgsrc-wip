# $NetBSD: buildlink3.mk,v 1.5 2008/10/30 21:10:05 bsadewitz Exp $

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../wip/MesaLib/buildlink3.mk"
.include "../../wip/glu/buildlink3.mk"
.include "../../wip/glut/buildlink3.mk"
