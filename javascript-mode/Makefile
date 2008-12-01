# $NetBSD: Makefile,v 1.5 2008/12/01 20:53:48 cheusov Exp $

DISTNAME=	javascript-2.1b1.el
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/script/script-mode/:S/.el//}
CATEGORIES=	devel editors
MASTER_SITES=	http://www.brgeight.se/downloads/emacs/
EXTRACT_SUFX=	

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.brgeight.se/
COMMENT=	Javascript major mode for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}

NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}

SRCS=			javascript.el

do-build:
.for f in ${SRCS}
	${EMACS_BIN} --no-init-file --no-site-file -batch	\
	      -f batch-byte-compile ${WRKSRC}/${f}
.endfor

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
	   ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
