# $NetBSD: Makefile,v 1.5 2006/03/12 00:51:40 jtonio Exp $

DISTNAME=     emacs-jabber-0.7
PKGNAME=      ${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=   chat
MASTER_SITES= ${MASTER_SITE_SOURCEFORGE:=emacs-jabber/}

MAINTAINER=   tonio@NetBSD.org
HOMEPAGE=     http://emacs-jabber.sourceforge.net/
COMMENT=      Minimal jabber client for emacs

DEPENDS+=     gnus>=5.10:../../mail/gnus
USE_TOOLS+=   makeinfo

INFO_FILES=   jabber.info

NO_CONFIGURE= yes

do-build:
	cd ${WRKSRC} && ${MAKEINFO} jabber.texi

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/emacs-jabber
	${INSTALL_DATA} ${WRKSRC}/*.el* ${EMACS_LISPPREFIX}/emacs-jabber
	${INSTALL_DATA} ${WRKSRC}/jabber.info ${PREFIX}/${INFO_DIR}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
