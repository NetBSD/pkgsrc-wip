# $NetBSD: Makefile,v 1.15 2015/01/15 15:34:15 leot1990 Exp $

DISTNAME=	vimb-2.8
CATEGORIES=	www
MASTER_SITES=	-https://github.com/fanglingsu/vimb/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

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
