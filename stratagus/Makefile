# $NetBSD: Makefile,v 1.3 2004/06/01 23:18:53 xtraeme Exp $
#

DISTNAME=	stratagus-2.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stratagus/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://stratagus.sourceforge.net/
COMMENT=	Real Time Strategy Engine

WRKSRC=		${WRKDIR}/stratagus-040305
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

USE_GNU_TOOLS+=	make

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
SUBST_CLASSES+=		ldl
SUBST_STAGE.ldl=	post-patch
SUBST_FILES.ldl=	configure
SUBST_SED.ldl=		-e 's,-ldl,,g'
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stratagus ${PREFIX}/bin/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
