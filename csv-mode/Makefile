# $NetBSD: Makefile,v 1.2 2012/09/24 18:26:56 asau Exp $

DISTNAME=	csv-mode-1.27
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	https://elpa.gnu.org/packages/
EXTRACT_SUFX=	.tar

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://www.emacswiki.org/emacs/CsvMode
COMMENT=	Emacs mode for editing comma-separated value files
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}

EMACS_VERSIONS_INCOMPATIBLE=	emacs20 xemacs214 xemacs215 xemacs214nox xemacs215nox

do-build:
	cd ${WRKSRC} \
		&& ${EMACS_BIN} -L . -batch -f batch-byte-compile *.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
