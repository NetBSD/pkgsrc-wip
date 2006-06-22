# $NetBSD: Makefile,v 1.1.1.1 2006/06/22 20:51:13 poppnk Exp $
#

DISTNAME=		redfang.2.5
PKGNAME=		redfang-2.5
CATEGORIES=		wip security
MASTER_SITES=		http://www.blackops.cn/tools/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.blackops.cn/tools/
COMMENT=		Scan for hidden bluetooth devices

WRKSRC=		${WRKDIR}/redfang-2.5
USE_TOOLS+=		pkg-config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fang ${PREFIX}/bin/redfang

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
