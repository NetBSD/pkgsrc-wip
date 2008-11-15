# $NetBSD: Makefile,v 1.15 2008/11/15 16:28:04 asau Exp $

PKGNAME=		fricas-1.0.4
DISTNAME=		${PKGNAME}-full
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://fricas.sourceforge.net/
COMMENT=		FriCAS is a fork of the Axiom computer algebra system

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

# Problems:
# 1. Building X11 interfaces requires X server running.
# We should run Xvfb for that stage.
# 2. ECL 0.9l (0.9.12 in pkgsrc) doesn't work, later version required.

.include "options.mk"

.if !empty(PKG_OPTIONS:Mx11)
post-build:
# This should start Xvfb temporarily:
	cd ${WRKSRC}/src/paste && ${MAKE_PROGRAM} gphts 
.endif

.include "../../mk/bsd.pkg.mk"
