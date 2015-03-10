# $NetBSD: Makefile,v 1.17 2015/03/10 19:26:20 leot1990 Exp $

DISTNAME=	vimb-2.9
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fanglingsu/}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

MAKE_ENV+=	MANDIR="${PREFIX}/${PKGMANDIR}"

.include "../../net/libsoup24/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
