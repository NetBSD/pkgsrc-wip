# $NetBSD: Makefile,v 1.3 2003/11/04 05:36:18 mpasternak Exp $
#

DISTNAME=		pitch-plugin-xmms
PKGNAME=		xmms-${DISTNAME:S/-xmms//}-0.0.1
CATEGORIES=		audio
MASTER_SITES=		http://www.lionking.org/%7Ejammet/temp/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.lionking.org/%7Ejammet/temp/
COMMENT=		Pitch control plugin for xmms

WRKSRC=		${WRKDIR}/pitch
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_DATA}	${WRKSRC}/libpitch.so ${PREFIX}/lib/xmms/Effect/

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
