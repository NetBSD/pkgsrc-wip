# $NetBSD: Makefile,v 1.2 2008/03/06 14:54:08 thomasklausner Exp $
#

DISTNAME=	libggz-0.0.14
PKGNAME=	ggz-libggz-0.0.14
PKGREVISION=	1
CATEGORIES=	wip
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://www.ggzgamingzone.org
COMMENT=	GGZ Gaming Zone libraries

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+= --enable-debug-gdb
CONFIGURE_ARGS+= --with-tls
CONFIGURE_ARGS+= --with-gcrypt

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
