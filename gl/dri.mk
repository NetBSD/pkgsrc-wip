# $NetBSD: dri.mk,v 1.2 2010/01/03 17:57:53 pallegra Exp $

BUILDLINK_API_DEPENDS.libdrm+= libdrm>=2.4.15
.  include "../../textproc/expat/buildlink3.mk"
.  include "../../x11/dri2proto/buildlink3.mk"
.  include "../../x11/glproto/buildlink3.mk"
.  include "../../x11/libXdamage/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../wip/libdrm/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  include "../../x11/xf86driproto/buildlink3.mk"
.  include "../../x11/xf86vidmodeproto/buildlink3.mk"
