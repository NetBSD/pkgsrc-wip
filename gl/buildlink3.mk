# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/01/03 14:32:17 pallegra Exp $

BUILDLINK_TREE+=	gl

.if !defined(GL_BUILDLINK3_MK)
GL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gl+=	gl>=7.7
BUILDLINK_PKGSRCDIR.gl?=	../../wip/gl

pkgbase:= gl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gl:Mdri)
.include "../../wip/gl/dri.mk"
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
.include "../../devel/pthread-stublib/buildlink3.mk"
.endif

.include "../../x11/libXext/buildlink3.mk"
.endif	# GL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gl
