# $NetBSD: Makefile,v 1.6 2014/02/01 18:51:52 leot1990 Exp $

DISTNAME=	2.2
PKGNAME=	vimb-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://github.com/fanglingsu/vimb/archive/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAKE_ENV+=	MANDIR="${PREFIX}/${PKGMANDIR}"

.include "../../net/libsoup24/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
