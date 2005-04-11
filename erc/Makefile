# $NetBSD: Makefile,v 1.2 2005/04/11 21:11:50 tvierling Exp $
#

DISTNAME=	erc-5.0.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=erc/}

MAINTAINER=	hsaliak@gmail.com
HOMEPAGE=	http://www.emacswiki.org/cgi-bin/wiki?EmacsIRCClient
COMMENT=	IRC client for Emacs

USE_GNU_TOOLS+=	make

.include "../../mk/emacs.mk"
.if ${EMACS_FLAVOR} == "xemacs"
	MAKE_FLAGS+= EMACS=xemacs
.endif

UNCOMPILED+=	erc-chess.el erc-bbdb.el erc-ibuffer.el erc-speak.el \
		erc-speedbar.el erc-compat.el

SRCS+=	erc-auto.el  erc-ezbounce.el erc-match.el erc-ring.el \
	erc-autoaway.el erc-fill.el  erc-menu.el  erc-sound.el \
	erc-autojoin.el erc-goodies.el  erc-nets.el  \
	erc-backend.el  erc-netsplit.el \
	erc-identd.el erc-nicklist.el erc-stamp.el \
	erc-button.el erc-imenu.el erc-nickserv.el erc-track.el \
	erc-lang.el  erc-notify.el erc-truncate.el \
	erc-list.el  erc-page.el  erc-xdcc.el \
	erc-complete.el erc-log.el  erc-pcomplete.el erc.el \
	erc-dcc.el  erc-maint.el erc-replace.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/erc
	cd ${WRKSRC} && ${INSTALL_DATA} ${UNCOMPILED}\
	 ${EMACS_LISPPREFIX}/erc
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} \
	${EMACS_LISPPREFIX}/erc

.include "../../mk/bsd.pkg.mk"
