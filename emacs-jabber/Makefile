# $NetBSD: Makefile,v 1.10 2008/11/06 19:56:11 cheusov Exp $

DISTNAME=	emacs-jabber-0.7.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=emacs-jabber/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://emacs-jabber.sourceforge.net/
COMMENT=	Minimal jabber client for emacs

#DEPENDS+=	${EMACS_PKGNAME_PREFIX}gnus>=5.10:../../mail/gnus
USE_TOOLS+=	makeinfo
INFO_FILES=	yes

NO_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/emacs-jabber ${EMACS_INFOPREFIX}

do-build:
	cd ${WRKSRC} && makeinfo jabber.texi

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el* ${DESTDIR}${EMACS_LISPPREFIX}/emacs-jabber
	${INSTALL_DATA} ${WRKSRC}/jabber.info ${DESTDIR}${EMACS_INFOPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
