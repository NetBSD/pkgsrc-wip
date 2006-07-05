# $NetBSD: Makefile,v 1.5 2006/07/05 16:42:51 thomasklausner Exp $
#

DISTNAME=	emacs-22.0.50
CATEGORIES=	editors
MASTER_SITES=	#

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

USE_TOOLS+=	gmake makeinfo

BUILD_TARGET=	bootstrap

CVS_REPOSITORIES=	emacs
CVS_ROOT.emacs=		${CVS_ROOT_GNU}/emacs
CVS_MODULE.emacs=	emacs

GNU_CONFIGURE=		yes

WRKSRC=		${WRKDIR}/emacs

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--with-tiff
CONFIGURE_ARGS+=	--with-gif
CONFIGURE_ARGS+=	--with-png

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs
PKG_OPTIONS_OPTIONAL_GROUPS= toolkit
PKG_OPTIONS_GROUP.toolkit= emacs-xaw3d motif gtk
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif
.elif !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=gtk
.elif !empty(PKG_OPTIONS:Memacs-xaw3d)
.include "../../x11/Xaw3d/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.else
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.endif

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	${PREFIX}/bin/emacs
CHECK_WRKREF_SKIP+=	${PREFIX}/bin/emacs-${PKGVERSION}

.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
