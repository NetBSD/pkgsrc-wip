# $NetBSD: Makefile,v 1.1.1.1 2007/06/25 23:13:17 hoka_adam Exp $
#

DISTNAME=	hunspell-1.1.5-3
PKGNAME=	hunspell-1.1.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hunspell/}

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://hunspell.sourceforge.net/
COMMENT=	Improved spellchecker

WRKSRC=			${WRKDIR}/hunspell-1.1.5
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-ui

PKGCONFIG_OVERRIDE+=	hunspell.pc.in

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
