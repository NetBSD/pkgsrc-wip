# $NetBSD: Makefile,v 1.12 2014/08/03 22:16:38 thomasklausner Exp $

DISTNAME=	vimb-2.6
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
.include "../../www/webkit1-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
