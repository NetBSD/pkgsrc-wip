# $NetBSD: Makefile,v 1.1.1.1 2003/04/04 10:03:43 bmeurer Exp $

PATCHDIR=		${.CURDIR}/../../editors/vim-share/patches
DISTINFO_FILE=		${.CURDIR}/distinfo

.include		"../../editors/vim-share/Makefile.common"

PKGNAME=		vim-gtk2-${VIM_VERSION}.${VIM_PATCHLEVEL}

COMMENT=		Vim editor (vi clone) with X11 GTK+ 2.0 GUI
MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}:../vim-share
CONFLICTS+=		vim-[0-9]* vim-gtk-[0-9]* vim-motif-[0-9]* vim-xaw-[0-9]*

PATCH_SITES+=		http://regexxer.sourceforge.net/vim/
PATCHFILES+=		vim-gtk2-20030316.patch.gz

USE_X11=		yes
CONFIGURE_ARGS+=	--enable-gui=gtk2
CONFIGURE_ARGS+=	--with-tlib=ncurses

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

post-install:
	for f in gvim.1 gview.1 rgvim.1 rgview.1; do			\
		${RM} -f ${PREFIX}/man/man1/$$f;			\
		${LN} -s vim.1 ${PREFIX}/man/man1/$$f;			\
	done
	for f in gvim gview rgvim rgview rvim rview; do			\
		${RM} -f ${PREFIX}/bin/$$f;				\
		${LN} -s vim ${PREFIX}/bin/$$f;				\
	done

.include "../../devel/ncurses/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
