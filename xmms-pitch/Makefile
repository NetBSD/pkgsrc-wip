# $NetBSD: Makefile,v 1.1.1.1 2003/09/03 16:48:50 mpasternak Exp $
#

DISTNAME=		pitch-plugin-xmms
PKGNAME=		xmms-${DISTNAME:S/-xmms//}
CATEGORIES=		audio
MASTER_SITES=		http://www.lionking.org/%7Ejammet/temp/

MAINTAINER=		michal@pasternak.w.lub.pl
HOMEPAGE=		http://www.lionking.org/%7Ejammet/temp/
COMMENT=		Pitch control plugin for xmms

WRKSRC=		${WRKDIR}/pitch
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_DATA}	${WRKSRC}/libpitch.so ${PREFIX}/lib/xmms/Effect/

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
