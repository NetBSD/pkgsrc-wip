# $NetBSD: Makefile,v 1.16 2008/12/18 05:28:26 asau Exp $

PKGNAME=		fricas-1.0.99
DISTNAME=		${PKGNAME}-full
CATEGORIES=		lang
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
# 2. ECL 0.9l (0.9.12 in pkgsrc) doesn't work, later version required.
# 3. DESTDIR support is broken:
# Starting interpsys
# spad = "/var/tmp/pkgobj/wip/fricas/work/fricas-1.0.4/target/i386--netbsdelf"
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
