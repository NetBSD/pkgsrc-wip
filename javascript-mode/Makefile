# $NetBSD: Makefile,v 1.1 2006/12/30 12:52:44 cheusov Exp $

DISTNAME=	javascript-2.0b7.el
PKGNAME=	${EMACS_PKGNAME_PREFIX}javascript-mode-2.0b7
CATEGORIES=	devel editors
MASTER_SITES=	http://web.comhem.se/~u34308910/emacs/
EXTRACT_SUFX=	.zip

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://web.comhem.se/~u34308910/emacs.html
COMMENT=	Javascript major mode for Emacs

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

SRCS=		javascript.el

do-build:
.for f in ${SRCS}
	${EMACS_BIN:Q} --no-init-file --no-site-file -batch	\
	      -f batch-byte-compile ${WRKSRC}/${f}
.endfor

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
	   ${EMACS_LISPPREFIX:Q}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
