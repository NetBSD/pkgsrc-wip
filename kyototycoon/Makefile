# $NetBSD: Makefile,v 1.1.1.1 2011/04/19 11:23:30 genolopolis Exp $
#

DISTNAME=	kyototycoon-0.9.38
CATEGORIES=	wip
MASTER_SITES=	http://fallabs.com/kyototycoon/pkg/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://fallabs.com/kyototycoon/
COMMENT=	Kyoto Tycoon is a lightweight database server for Kyoto Cabinet
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--enable-lua

PKGCONFIG_OVERRIDE+=	kyototycoon.pc.in

.include "../../lang/lua/buildlink3.mk"
.include "../../wip/kyotocabinet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
