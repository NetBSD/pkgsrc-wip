# $NetBSD: Makefile,v 1.8 2013/12/05 23:31:35 wiz Exp $

DISTNAME=	libquvi-scripts-0.9.20131130
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quvi/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://quvi.sourceforge.net/
COMMENT=	Scripts for libquvi
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	quvi<=0.2.19

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

CONFIGURE_ARGS+=	--with-nsfw

PKGCONFIG_OVERRIDE+=	libquvi-scripts.pc.in

.include "../../lang/lua/luaversion.mk"
DEPENDS+=	${LUA_PKGPREFIX}-socket-[0-9]*:../../net/lua-socket
DEPENDS+=	${LUA_PKGPREFIX}-expat-[0-9]*:../../textproc/lua-expat
#DEPENDS+=	${LUA_PKGPREFIX}-json-[0-9]*:../../wip/lua-json

.include "../../mk/bsd.pkg.mk"
