# $NetBSD: Makefile,v 1.14 2012/09/24 18:26:55 asau Exp $
#

DISTNAME=		cream-0.41
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cream/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://cream.sourceforge.net/
COMMENT=		Usability add-on for Vim
LICENSE=		gnu-gpl-v3

DEPENDS+=		{vim-gtk2,vim-gtk,vim-kde,vim-motif}>=7.0:../../editors/vim-gtk2

NO_BUILD=		yes

.include "../../editors/vim-share/version.mk"
VIMRUNTIME=		${DESTDIR}${PREFIX}/share/vim/${VIM_SUBDIR}
PLIST_SUBST+=		VIM_SUBDIR=${VIM_SUBDIR:Q}
INSTALLATION_DIRS+=	bin share/applications share/icons/cream

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/addons
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/bitmaps
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/docs
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/docs-html
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/filetypes
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/help
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/lang
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/spelldicts
	${INSTALL_DATA} ${WRKSRC}/creamrc ${VIMRUNTIME}/cream/
	${INSTALL_DATA} ${WRKSRC}/*.vim ${VIMRUNTIME}/cream/
	${INSTALL_DATA} ${WRKSRC}/addons/*.vim ${VIMRUNTIME}/cream/addons/
	${INSTALL_DATA} ${WRKSRC}/bitmaps/*.xpm ${VIMRUNTIME}/cream/bitmaps/
	${INSTALL_DATA} ${WRKSRC}/bitmaps/*.bmp ${VIMRUNTIME}/cream/bitmaps/
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${VIMRUNTIME}/cream/docs/
	${INSTALL_DATA} ${WRKSRC}/docs-html/* ${VIMRUNTIME}/cream/docs-html/
	${INSTALL_DATA} ${WRKSRC}/filetypes/*.vim ${VIMRUNTIME}/cream/filetypes/
	${INSTALL_DATA} ${WRKSRC}/help/*.txt ${VIMRUNTIME}/cream/help/
	${INSTALL_DATA} ${WRKSRC}/lang/*.vim ${VIMRUNTIME}/cream/lang/
	${INSTALL_DATA} ${WRKSRC}/cream.ico ${DESTDIR}${PREFIX}/share/icons/cream/
	${INSTALL_DATA} ${WRKSRC}/cream.png ${DESTDIR}${PREFIX}/share/icons/cream/
	${INSTALL_DATA} ${WRKSRC}/cream.svg ${DESTDIR}${PREFIX}/share/icons/cream/
	${INSTALL_DATA} ${WRKSRC}/cream.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_SCRIPT} ${WRKSRC}/cream ${DESTDIR}${PREFIX}/bin/

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
