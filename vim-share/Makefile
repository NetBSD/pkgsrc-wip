# $NetBSD: Makefile,v 1.1.1.1 2006/05/06 15:41:27 marttikuparinen Exp $

PKGNAME=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}
#PKGREVISION=		1

COMMENT=		Data files for the vim editor (vi clone)

.include		"Makefile.common"

CONFIGURE_ARGS+=	--disable-gui

BUILD_TARGET=		vim
INSTALL_TARGET=		installruntime installmacros installtutor installtools
USE_TOOLS+=		awk
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} TOOLS_AWK=${TOOLS_AWK:Q}

PLIST_SUBST+=		VIM_SUBDIR=${VIM_SUBDIR:Q}

.include "../../mk/bsd.pkg.mk"
