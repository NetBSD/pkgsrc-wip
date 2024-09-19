# $NetBSD: Makefile,v 1.4 2012/10/03 15:09:54 asau Exp $
#

DISTNAME=	mic-paren
PKGNAME=	mic-paren-3.8
CATEGORIES=	editors
MASTER_SITES=	http://www.emacswiki.org/cgi-bin/emacs/download/
EXTRACT_SUFX=	.el

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.emacswiki.org/cgi-bin/wiki/${DISTNAME}.el
COMMENT=	Advanced highlighting of parenthesis
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX}

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile ${DISTNAME}.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
