# $NetBSD: Makefile,v 1.4 2011/09/21 05:13:34 phonohawk Exp $
#

DISTNAME=		css-mode
PKGNAME=		${DISTNAME}-1.0
PKGREVISION=	1
CATEGORIES=		editors
MASTER_SITES=	http://www.brgeight.se/downloads/emacs/
EXTRACT_SUFX=	.el

MAINTAINER=		pho@cielonegro.org
HOMEPAGE=		http://www.brgeight.se/
COMMENT=		CSS editing mode for Emacs
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}
NO_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=		${EMACS_LISPPREFIX}

do-build:
	cd ${WRKSRC} && \
		${EMACS_BIN} -batch -f batch-byte-compile *.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
