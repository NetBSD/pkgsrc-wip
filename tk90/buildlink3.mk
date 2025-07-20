# $NetBSD: buildlink3.mk,v 1.1 2025/03/08 11:47:41 scole Exp $

BUILDLINK_TREE+=	tk90

.if !defined(TK_BUILDLINK3_MK)
TK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk90+=	tk90>=9.0.1
BUILDLINK_ABI_DEPENDS.tk90+=	tk90>=9.0.1
BUILDLINK_PKGSRCDIR.tk90?=	../../wip/tk90

BUILDLINK_PASSTHRU_DIRS+=		${PREFIX}/tcl/9.0
BUILDLINK_FILES.tk90+=			tcl/9.0/bin/*
BUILDLINK_FNAME_TRANSFORM.tk90+=	-e s,tcl/9.0/bin,bin,
BUILDLINK_FNAME_TRANSFORM.tk90+=	-e s,tcl/9.0/lib/pkgconfig,lib/pkgconfig,

BUILDLINK_FILES.tk90+=	bin/wish*
#
# Make "-ltk90" resolve into "-ltk9.0", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk90:tk9.0

TK90_SUBDIR=		tcl/9.0

TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk90}/lib/tkConfig.sh

_TOOLS_USE_PKGSRC.wish=	yes

WISH=	${PREFIX}/bin/wish

pkgbase := tk90
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.tk90:Mxft2}
.  include "../../x11/libXft/buildlink3.mk"
.endif
.if empty(PKG_BUILD_OPTIONS.tk90:Maqua)
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXScrnSaver/buildlink3.mk"
.endif
.include "../../wip/tcl90/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # TK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk90
