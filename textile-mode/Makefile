# $NetBSD: Makefile,v 1.1 2014/03/19 07:34:07 phonohawk Exp $
#

DISTNAME=	textile-mode
PKGNAME=	${DISTNAME}-2006.03.30
CATEGORIES=	editors
MASTER_SITES=	http://dev.nozav.org/scripts/
EXTRACT_SUFX=	.el

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://www.emacswiki.org/emacs/TextileMode
COMMENT=	Emacs mode for editing Textile documents
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_CONFIGURE=	YES

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}

do-build:
	cd ${WRKSRC} \
		&& ${EMACS_BIN} -batch -f batch-byte-compile ${DISTNAME}.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
