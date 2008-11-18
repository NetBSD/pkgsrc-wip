# $NetBSD: Makefile,v 1.1.1.1 2008/11/18 02:15:36 makoto Exp $
#

DISTNAME=	emacs-w3m-1.4.50
PKGNAME=	emacs-w3m-1.4.50
PKGREVISION=	${_CVS_PKGVERSION:S/.//g}

CATEGORIES=	editors
MASTER_SITES=	#

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://www.namazu.org/emacs-w3m
COMMENT=	Emacs frontend for w3m browser

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	makeinfo gzip autoconf

#CONFLICTS+=

BUILD_TARGET=

CVS_REPOSITORIES=	emacs-w3m
CVS_ROOT.emacs-w3m=	:pserver:anonymous:@cvs.namazu.org:/storage/cvsroot


GNU_CONFIGURE=		yes
INFO_FILES=		yes
#REPLACE_PERL=		lib-src/grep-changelog

WRKSRC=		${WRKDIR}/emacs-w3m

CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN:Q}

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE

PLIST_SRC+=		PLIST

pre-configure:
	(cd ${WRKSRC} ; autoconf)

#.include "../../mk/oss.buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
