# $NetBSD: buildlink3.mk,v 1.3 2008/02/28 13:25:22 bsadewitz Exp $

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../wip/MesaLib/buildlink3.mk"
.include "../../wip/glu/buildlink3.mk"
.include "../../wip/glut/buildlink3.mk"
