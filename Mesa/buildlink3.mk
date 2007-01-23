# $NetBSD: buildlink3.mk,v 1.1 2007/01/23 17:48:28 bsadewitz Exp $

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../wip/MesaLib/buildlink3.mk"
.include "../../wip/glu/buildlink3.mk"
.include "../../wip/glut/buildlink3.mk"
