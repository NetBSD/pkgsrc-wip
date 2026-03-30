# $NetBSD: $

PKGNAME=	vim-classic-lang-${VIM_VERSION}.${VIM_PATCHLEVEL}

.include "../../wip/vim-classic-share/Makefile.common"

COMMENT=	Language files for the vim-classic editor (vi clone)

DEPENDS+=	vim-classic-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../wip/vim-classic-share

USE_TOOLS+=	msgfmt
BUILD_TARGET=	languages
INSTALL_TARGET=	install-languages

PLIST_SUBST+=	VIM_SUBDIR=${VIM_SUBDIR}

BUILDLINK_DEPMETHOD.gettext-lib?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
