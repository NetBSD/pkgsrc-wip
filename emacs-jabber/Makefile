# $NetBSD: Makefile,v 1.4 2005/10/16 12:18:17 jtonio Exp $

DISTNAME=     emacs-jabber-0.6.1
PKGNAME=      ${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=   chat
MASTER_SITES= ${MASTER_SITE_SOURCEFORGE:=emacs-jabber/}

MAINTAINER=   tonio@NetBSD.org
HOMEPAGE=     http://intellectronica.net/emacs-jabber/
COMMENT=      Minimal jabber client for emacs

DEPENDS+=     gnus>=5.10:../../mail/gnus

INFO_FILES=   jabber.info

NO_CONFIGURE= yes
NO_BUILD=     yes

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/emacs-jabber
	${INSTALL_DATA} ${WRKSRC}/*.el* ${EMACS_LISPPREFIX}/emacs-jabber
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/emacs-jabber
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${PREFIX}/share/doc/html/emacs-jabber
	${INSTALL_DATA} ${WRKSRC}/jabber.info ${PREFIX}/${INFO_DIR}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
