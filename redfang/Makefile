# $NetBSD: Makefile,v 1.3 2012/10/07 14:16:00 asau Exp $
#

DISTNAME=		redfang.2.5
PKGNAME=		redfang-2.5
CATEGORIES=		wip security
MASTER_SITES=		http://www.blackops.cn/tools/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.blackops.cn/tools/\#tools
COMMENT=		Scan for hidden bluetooth devices

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fang ${DESTDIR}${PREFIX}/bin/redfang

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
