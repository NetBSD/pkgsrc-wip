# $NetBSD: Makefile,v 1.1.1.1 2007/05/31 19:31:15 hoka_adam Exp $

DISTNAME=       bsdinstaller-20070528
PKGNAME=	lua50-dfui-0.1
CATEGORIES=	devel

MASTER_SITES=   http://rnrdoctor.sytes.net/~replaced/bsdinstaller/
WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/lib/lua/dfui/

MAINTAINER=	adam.hoka@gmail.com
COMMENT=	DFUI binding for Lua 5.0.x


do-install:
	${INSTALL_PROGRAM} -o root -g wheel -m 444 ${WRKSRC}/ldfui.so ${PREFIX}/lib/lua/5.0/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/dfui.lua ${PREFIX}/share/lua/5.0/

.include "../../devel/libaura/buildlink3.mk"
.include "../../wip/libdfui/buildlink3.mk"
.include "../../wip/lua50/buildlink3.mk"
.include "../../wip/lua50-compat51/buildlink3.mk"
.include "../../wip/lua50-posix/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
