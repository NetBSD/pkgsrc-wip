# $NetBSD: Makefile,v 1.1.1.1 2010/10/07 13:24:07 makoto Exp $

DISTNAME=		auctex-11.86
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		${_CVS_PKGVERSION:S/.//g}

CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=auctex/}

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://www.gnu.org/software/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs

WRKSRC=			${WRKDIR}/auctex
PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	${EMACS_INFOPREFIX} \
			${EMACS_LISPPREFIX}/auctex

EMACS_MODULES=		base

USE_TOOLS+=		gmake autoconf makeinfo perl
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${EMACS_FLAVOR}}
CONFIGURE_ARGS+=	--disable-preview

MAKEFLAGS+=		EMACS=${EMACS_BIN:Q}
MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX:Q}
INFO_FILES=		YES

CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX}
CONFIGURE_ARGS.xemacs=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp||}

CVS_ROOT.auctex=	:pserver:anonymous:@cvs.savannah.gnu.org:/sources/auctex
CVS_REPOSITORIES=	auctex

# separate TeX dependency.
.include "options.mk"

pre-configure:
			(cd ${WRKSRC} && ./autogen.sh)

.include "../../editors/emacs/modules.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
