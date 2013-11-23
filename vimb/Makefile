# $NetBSD: Makefile,v 1.3 2013/11/23 15:06:34 leot1990 Exp $

DISTNAME=	2.0
PKGNAME=	vimb-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://github.com/fanglingsu/vimb/archive/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

FETCH_USING=	curl	# XXX: https://

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAKE_ENV+=	MANDIR="${PREFIX}/${PKGMANDIR}"

.include "../../net/libsoup24/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
