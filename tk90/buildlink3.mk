# $NetBSD: buildlink3.mk,v 1.1 2025/03/08 11:47:41 scole Exp $

BUILDLINK_TREE+=	tk

.if !defined(TK_BUILDLINK3_MK)
TK_BUILDLINK3_MK:=

# BUILDLINK_API_DEPENDS.tk+=	tk>=8.5.7
# BUILDLINK_ABI_DEPENDS.tk+=	tk>=8.6.13nb1
# BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk
# xxx
BUILDLINK_API_DEPENDS.tk+=	tk>=9.0.1
BUILDLINK_ABI_DEPENDS.tk+=	tk>=9.0.1
BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk90

BUILDLINK_FILES.tk+=	bin/wish*
#
# Make "-ltk" and "-ltk8.6" resolve into "-ltk86", so that we don't
# need to patch so many Makefiles.
#
# BUILDLINK_TRANSFORM+=	l:tk:tk86
# BUILDLINK_TRANSFORM+=	l:tk8.6:tk86
# xxx
BUILDLINK_TRANSFORM+=	l:tk:tk90
BUILDLINK_TRANSFORM+=	l:tk9.0:tk90

TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

_TOOLS_USE_PKGSRC.wish=	yes

WISH=	${PREFIX}/bin/wish

pkgbase := tk
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.tk:Mxft2}
.  include "../../x11/libXft/buildlink3.mk"
.endif
.if empty(PKG_BUILD_OPTIONS.tk:Maqua)
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXScrnSaver/buildlink3.mk"
.endif
# xxx
#.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl90/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # TK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk
