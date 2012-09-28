# $NetBSD: Makefile,v 1.6 2012/09/28 23:21:48 asau Exp $
#

DISTNAME=		fish-1.23.1
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fish/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fishshell.org/
COMMENT=		User friendly command line shell for UNIX-like operating systems
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-xsel
USE_TOOLS+=		gmake

EGDIR=			${PREFIX}/share/examples/fish
INSTALL_ENV+=		EGDIR=${EGDIR}

BUILD_DEPENDS+=		doxygen>=1.2.14:../../devel/doxygen

PKG_SHELL=		bin/fish

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
