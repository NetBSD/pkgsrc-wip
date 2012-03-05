# $NetBSD: Makefile,v 1.1.1.1 2012/03/05 06:59:32 phonohawk Exp $
#

DISTNAME=	csv-mode
PKGNAME=	${DISTNAME}-20040823
CATEGORIES=	editors
MASTER_SITES=	http://www.emacswiki.org/emacs/download/
EXTRACT_SUFX=	.el

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.emacswiki.org/emacs/CsvMode
COMMENT=	Emacs mode for editing comma-separated value files
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_CONFIGURE=	YES

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}

do-build:
	cd ${WRKSRC} \
		&& ${EMACS_BIN} -batch -f batch-byte-compile ${DISTNAME}.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
