# $NetBSD: Makefile,v 1.3 2014/06/01 12:49:37 thomasklausner Exp $
#

DISTNAME=	mediawiki
PKGNAME=	mediawiki-mode-2.2.4
CATEGORIES=	editors
MASTER_SITES=	https://launchpad.net/mediawiki-el/2.2/${PKGVERSION_NOREV}/+download/
EXTRACT_SUFX=	.el

# FIXME: pkgsrc is not currently able to fetch distfiles from https
# web servers. See http://gnats.netbsd.org/45680

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.emacswiki.org/emacs/MediaWikiMode
COMMENT=	Emacs frontend for MediaWiki
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_CONFIGURE=	YES

do-build:
	${RUN} cd ${WRKSRC} && \
		${EMACS_BIN} -batch -f batch-byte-compile ${DISTNAME}.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
