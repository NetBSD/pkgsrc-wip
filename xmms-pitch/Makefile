# $NetBSD: Makefile,v 1.4 2004/03/09 13:31:19 mpasternak Exp $
#

DISTNAME=		pitch-plugin-xmms
PKGNAME=		xmms-${DISTNAME:S/-xmms//}-0.0.1
CATEGORIES=		audio
MASTER_SITES=		http://www.lionking.org/%7Ejammet/temp/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.lionking.org/%7Ejammet/temp/
COMMENT=		Pitch control plugin for xmms

WRKSRC=			${WRKDIR}/pitch
USE_BUILDLINK3=		yes

do-install:
	${INSTALL_DATA}	${WRKSRC}/libpitch.so ${PREFIX}/lib/xmms/Effect/

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
