# $NetBSD: Makefile,v 1.1.1.1 2004/10/06 04:15:01 dhowland Exp $
#

DISTNAME=		cream-0.30
CATEGORIES=		editors
MASTER_SITES=		http://cream.sourceforge.net/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://cream.sourceforge.net/
COMMENT=		Usability add-on for Vim

DEPENDS+=		vim-gtk2-6.*:../../editors/vim-gtk2

NO_BUILD=		# defined

VIM_SUBDIR=		vim63
VIMRUNTIME=		${PREFIX}/share/vim/${VIM_SUBDIR}
PLIST_SUBST+=		VIM_SUBDIR=${VIM_SUBDIR}

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/addons
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/bitmaps
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/docs
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/help
	${INSTALL_DATA_DIR} ${VIMRUNTIME}/cream/spelldicts
	${INSTALL_DATA} ${WRKSRC}/creamrc ${VIMRUNTIME}/cream/
	${INSTALL_DATA} ${WRKSRC}/*.vim ${VIMRUNTIME}/cream/
	${INSTALL_DATA} ${WRKSRC}/addons/*.vim ${VIMRUNTIME}/cream/addons/
	${INSTALL_DATA} ${WRKSRC}/bitmaps/*.xpm ${VIMRUNTIME}/cream/bitmaps/
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${VIMRUNTIME}/cream/docs/
	${INSTALL_DATA} ${WRKSRC}/help/*.txt ${VIMRUNTIME}/cream/help/
	${INSTALL_DATA} ${WRKSRC}/spelldicts/*.vim ${VIMRUNTIME}/cream/spelldicts/
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/cream
	${INSTALL_DATA} ${WRKSRC}/cream.png ${PREFIX}/share/icons/cream/
	${INSTALL_DATA} ${WRKSRC}/cream.svg ${PREFIX}/share/icons/cream/
	${INSTALL_SCRIPT} ${WRKSRC}/cream ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
