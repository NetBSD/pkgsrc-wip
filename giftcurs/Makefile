# $NetBSD: Makefile,v 1.5 2004/05/07 01:57:55 xtraeme Exp $
#

DISTNAME=	giFTcurs-0.6.0
PKGNAME=	${DISTNAME:S/FT/ft/}
CATEGORIES=	net
MASTER_SITES=	http://savannah.nongnu.org/download/giftcurs/giFTcurs.pkg/0.6.0/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/giftcurs/
COMMENT=	Curses frontend to the giFT daemon

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
USE_NCURSES=		yes
CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
.include "../../devel/ncurses/buildlink2.mk"
.endif

.include "../../devel/glib2/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
