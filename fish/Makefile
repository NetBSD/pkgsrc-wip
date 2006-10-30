# $NetBSD: Makefile,v 1.1.1.1 2006/10/30 20:20:54 hugor Exp $
#
DISTNAME=	fish-1.21.12
CATEGORIES=	shells
MASTER_SITES=	http://roo.no-ip.org/fish/files/1.21.12/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://roo.no-ip.org/fish/
COMMENT=	User friendly command line shell for UNIX-like operating systems

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+= --without-xsel
USE_NCURSES=	yes
USE_TOOLS+=	gmake

INSTALL_MAKE_FLAGS+=   ${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

BUILD_DEPENDS+=	doxygen>1.2.14:../../devel/doxygen

PKG_SHELL=	bin/fish

.include	"../../devel/ncurses/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
