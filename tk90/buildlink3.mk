# $NetBSD: buildlink3.mk,v 1.1 2025/03/08 11:47:41 scole Exp $

BUILDLINK_TREE+=	tk

.if !defined(TK_BUILDLINK3_MK)
TK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk+=	tk>=9.0.1
BUILDLINK_ABI_DEPENDS.tk+=	tk>=9.0.1
# xxx
BUILDLINK_PKGSRCDIR.tk?=	../../wip/tk90

BUILDLINK_FILES.tk+=	bin/wish*
#
# Make "-ltk" resolve into "-ltk9.0", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk9.0

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
.include "../../wip/tcl90/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # TK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk
