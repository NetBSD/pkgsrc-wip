# $NetBSD: Makefile,v 1.7 2009/07/31 22:18:50 minskim Exp $
#

DISTNAME=	erc-5.3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNU:=erc/}

MAINTAINER=	hsaliak@gmail.com
HOMEPAGE=	http://www.emacswiki.org/cgi-bin/wiki?ERC
COMMENT=	IRC client for Emacs

USE_TOOLS+=	gmake makeinfo
INFO_FILES=	yes

.include "../../editors/emacs/modules.mk"
.if ${EMACS_FLAVOR} == "xemacs"
	MAKE_FLAGS+= EMACS=xemacs
.endif

.if ${EMACS_VERSION_MAJOR} == "22"
SUBST_CLASSES+=		log
SUBST_STAGE.log=	post-patch
SUBST_FILES.log=	erc-log.el
SUBST_SED.log=		-e 's|local-write-file-hooks|write-file-functions|g'
SUBST_SED.log+=		-e 's|write-file-hooks|write-file-functions|g'
.endif

post-patch:
	cd ${WRKSRC} && makeinfo erc.texi

UNCOMPILED+=	erc-chess.el erc-bbdb.el erc-ibuffer.el erc-speak.el \
		erc-speedbar.el erc-compat.el

SRCS+=	erc-auto.el erc-autoaway.el erc-backend.el erc-button.el \
	erc-capab.el erc-dcc.el erc-ezbounce.el erc-fill.el \
	erc-goodies.el erc-hecomplete.el erc-identd.el \
	erc-imenu.el erc-join.el erc-lang.el erc-list.el erc-log.el \
	erc-maint.el erc-match.el erc-menu.el erc-netsplit.el \
	erc-networks.el erc-nicklist.el erc-notify.el erc-page.el \
	erc-pcomplete.el erc-replace.el erc-ring.el erc-services.el \
	erc-sound.el erc-spelling.el erc-stamp.el \
	erc-track.el erc-truncate.el erc-viper.el erc-xdcc.el \
	erc.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/erc
	cd ${WRKSRC} && ${INSTALL_DATA} ${UNCOMPILED}\
	 ${EMACS_LISPPREFIX}/erc
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} \
	${EMACS_LISPPREFIX}/erc

.include "../../mk/bsd.pkg.mk"
