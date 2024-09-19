# $NetBSD: Makefile,v 1.3 2012/09/28 22:07:33 asau Exp $
#

DISTNAME=	session-2.3
PKGNAME=	emacs-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=${PKGBASE}/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://emacs-session.sourceforge.net/
COMMENT=	Session Management for Emacs
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/session
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=		${EMACS_LISPPREFIX}
INSTALLATION_DIRS+=		share/doc/${PKGBASE}

do-build:
	cd ${WRKSRC} && \
		${EMACS_BIN} -batch -f batch-byte-compile lisp/*.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.elc ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/README     ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
