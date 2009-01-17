# $NetBSD: Makefile,v 1.18 2009/01/17 13:11:31 asau Exp $

PKGNAME=		fricas-1.0.99
DISTNAME=		${PKGNAME}-full
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://fricas.sourceforge.net/
COMMENT=		FriCAS is a fork of the Axiom computer algebra system

# Get it from Subversion repository:
SVN_REPOSITORIES=	fricas
SVN_ROOT.fricas=	https://fricas.svn.sourceforge.net/svnroot/fricas/trunk
SVN_MODULE.fricas=	fricas

#WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
WRKSRC=			${WRKDIR}/fricas

BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

# Problems:
# 1. Building X11 interfaces requires X server running.
# We should run Xvfb for that stage.
# 4. Emacs files should go into "site-lisp".

#INSTALLATION_DIRS=	lib/fricas/emacs

.include "options.mk"

.if !empty(PKG_OPTIONS:Mx11)
post-build:
# This should start Xvfb temporarily:
	cd ${WRKSRC}/src/paste && ${MAKE_PROGRAM} gphts 
# xvfb-run --server-args="-screen 0 1024x768x24" --auto-servernum -n 0 make gphts
.endif

.include "../mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
