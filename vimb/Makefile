# $NetBSD: Makefile,v 1.20 2015/07/12 00:38:17 thomasklausner Exp $

DISTNAME=	vimb-2.10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fanglingsu/}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

EGDIR=		${PREFIX}/share/examples/vimb

MAKE_ENV+=	EXAMPLEDIR="${EGDIR}"
MAKE_ENV+=	MANDIR="${PREFIX}/${PKGMANDIR}"

.include "../../net/libsoup/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
