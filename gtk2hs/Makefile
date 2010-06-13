# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:06 thomasklausner Exp $
#

DISTNAME=	gtk2hs-0.9.13
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2hs/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://gtk2hs.sourceforge.net/
COMMENT=	GUI Library for Haskell based on Gtk

GNU_CONFIGURE=	yes
USE_TOOLS+=	bash pkg-config gmake

CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--without-pkgreg
CONFIGURE_ARGS+=	--disable-split-objs

# Substitutions for INSTALL and DEINSTALL.
FILES_SUBST+=	HASKELL_PKG_BIN=${PREFIX}/bin/ghc-pkg
FILES_SUBST+=	GTK2HS_LIBDIR=${PREFIX}/lib/gtk2hs

PLIST_SRC= # empty
.include "options.mk"
PLIST_SRC+= PLIST.common

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "Darwin"
CPP_PRECOMP_FLAGS= # empty
.endif
