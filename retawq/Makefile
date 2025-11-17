# $NetBSD$

DISTNAME=	retawq-0.2.6c
CATEGORIES=	www
MASTER_SITES=	http://prdownloads.sourceforge.net/retawq/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://prdownloads.sourceforge.net/retawq/
COMMENT=	Interactive, multi-threaded network client for text terminals
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--path-archprefix=${PREFIX}
CONFIGURE_ARGS+=	--path-prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-i18n
CONFIGURE_ARGS+=	--enable-local-cgi
CONFIGURE_ARGS+=	--enable-ipv6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
