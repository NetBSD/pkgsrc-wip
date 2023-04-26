# $NetBSD$

VERSION=	17.2.1
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fxbois/}
GITHUB_PROJECT=	web-mode
GITHUB_TAG=	v${VERSION}


LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fxbois/web-mode/
COMMENT=	Emacs mode for html/php editting

USE_LANGUAGES=	# none
USE_TOOLS=	bash

EMACS_SITE_LISP=	${PREFIX}/share/emacs/site-lisp

INSTALLATION_DIRS=	${EMACS_SITE_LISP}/web-model/

do-build:
	(cd ${WRKSRC}; sh run.sh)

do-install:
	${MKDIR}	${DESTDIR}/${EMACS_SITE_LISP}/web-model/
	(cd ${WRKSRC}; \
	${INSTALL} web-mode.el ${DESTDIR}${EMACS_SITE_LISP}/web-model/; \
	)

.include "../../mk/bsd.pkg.mk"
