# $NetBSD: Makefile,v 1.7 2006/05/19 16:51:41 ykomatsu Exp $
#

DISTNAME=		pitch-plugin-xmms
PKGNAME=		xmms-${DISTNAME:S/-xmms//}-0.0.1
CATEGORIES=		audio
MASTER_SITES=		http://www.lionking.org/%7Ejammet/temp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lionking.org/%7Ejammet/temp/
COMMENT=		Pitch control plugin for xmms

WRKSRC=			${WRKDIR}/pitch

do-install:
	${INSTALL_DATA}	${WRKSRC}/libpitch.so ${PREFIX}/lib/xmms/Effect/

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
