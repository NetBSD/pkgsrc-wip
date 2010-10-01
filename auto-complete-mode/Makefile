# $NetBSD: Makefile,v 1.1.1.1 2010/10/01 06:12:03 phonohawk Exp $
#

DISTNAME=		auto-complete-1.3
CATEGORIES=		editors
MASTER_SITES=	http://cx4a.org/pub/auto-complete/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		pho@cielonegro.org
HOMEPAGE=		http://cx4a.org/software/auto-complete/index.html
COMMENT=		The most intelligent auto-completion extension for GNU Emacs
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

MESSAGE_SUBST+=         LISPDIR=${EMACS_LISPPREFIX:Q}
MESSAGE_SUBST+=			PKGBASE=${PKGBASE:Q}
INSTALLATION_DIRS=		${EMACS_LISPPREFIX}/${PKGBASE}
INSTALLATION_DIRS=		${EMACS_LISPPREFIX}/${PKGBASE}/ac-dict

do-build:
	cd ${WRKSRC} && \
		${EMACS_BIN} -Q -L . -batch -f batch-byte-compile *.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el   ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.elc  ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/dict/* ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}/ac-dict

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
