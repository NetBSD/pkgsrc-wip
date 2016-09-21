# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:36 asau Exp $

DISTNAME=	leim-${VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	Libraries of Emacs Input Methods (for emacs22)


CVS_REPOSITORIES=	emacs
CVS_ROOT.emacs=		${CVS_ROOT_GNU}/emacs
CVS_MODULE.emacs=	emacs

#WRKSRC=		${WRKDIR}/emacs-${VERSION}/leim
WRKSRC=		${WRKDIR}/emacs/leim
PATCHDIR=	${PKGDIR}/../emacs-git/patches

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

VERSION=	22.0.93

EMACS_VERSIONS_ACCEPTED=	emacs22 emacs22nox

CONFIG_GUESS_OVERRIDE=	../config.guess
CONFIG_SUB_OVERRIDE=	../config.sub

post-extract:
	@${ECHO} '#!/bin/sh' >${WRKSRC}/configure
	@${ECHO} 'cd ..' >>${WRKSRC}/configure
	@${ECHO} 'exec ./configure $$*' >>${WRKSRC}/configure
	@${CHMOD} +x ${WRKSRC}/configure

.include "../../mk/bsd.prefs.mk"

post-install:
	@${CHOWN} -R ${ROOT_USER} ${PREFIX}/share/emacs/${VERSION}/leim

.include "../../editors/emacs/modules.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
