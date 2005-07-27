# $NetBSD: Makefile,v 1.6 2005/07/27 16:31:34 thomasklausner Exp $
#

DISTNAME=		pitch-plugin-xmms
PKGNAME=		xmms-${DISTNAME:S/-xmms//}-0.0.1
CATEGORIES=		audio
MASTER_SITES=		http://www.lionking.org/%7Ejammet/temp/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.lionking.org/%7Ejammet/temp/
COMMENT=		Pitch control plugin for xmms

WRKSRC=			${WRKDIR}/pitch

do-install:
	${INSTALL_DATA}	${WRKSRC}/libpitch.so ${PREFIX}/lib/xmms/Effect/

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
