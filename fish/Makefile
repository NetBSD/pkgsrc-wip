# $NetBSD: Makefile,v 1.4 2010/11/11 22:42:06 shattered Exp $
#

DISTNAME=		fish-1.23.0
CATEGORIES=		shells
MASTER_SITES=		http://www.fishshell.org/files/1.23.0/

MAINTAINER=		hugor@users.sourceforge.net
HOMEPAGE=		http://www.fishshell.org/
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
