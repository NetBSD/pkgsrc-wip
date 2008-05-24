# $NetBSD: Makefile,v 1.3 2008/05/24 15:34:10 tnn2 Exp $
#
DISTNAME=		fish-1.23.0
CATEGORIES=		shells
MASTER_SITES=		http://www.fishshell.org/files/1.23.0/

MAINTAINER=		hugor@users.sourceforge.net
HOMEPAGE=		http://roo.no-ip.org/fish/
COMMENT=		User friendly command line shell for UNIX-like operating systems

PKG_DESTDIR_SUPPORT=	destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	 --sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-xsel
USE_NCURSES=		yes
USE_TOOLS+=		gmake

INSTALL_MAKE_FLAGS+=   ${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

#Should be an option (?)
#BUILD_DEPENDS+=	doxygen>1.2.14:../../devel/doxygen

PKG_SHELL=	bin/fish

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
