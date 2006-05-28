# $NetBSD: Makefile,v 1.4 2006/05/28 10:38:06 cheusov Exp $

DISTNAME=		dictem-0.8
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
#PKGREVISION=		1
CATEGORIES=		textproc editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dictem/} \
                        http://www.mova.org/~cheusov/pub/dictem/

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://www.freshmeat.net/projects/dictem/
COMMENT=		Dictionary client (RFC-2229) for [X]Emacs

DEPENDS+=		dict-client>=1.9.14:../../textproc/dict-client
#MESSAGE_SUBST+=		PREFIX=${PREFIX}

SRCS=			dictem.el
DOCS=			README NEWS COPYING ChangeLog

do-build:
	for f in ${SRCS}; do						\
		${EMACS_BIN:Q} --no-init-file --no-site-file -batch	\
			-f batch-byte-compile ${WRKSRC}/$$f;		\
	done

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX:Q};			\
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${EMACS_LISPPREFIX:Q};				\
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE};		\
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS}				\
			${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
