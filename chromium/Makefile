# $NetBSD: Makefile,v 1.1.1.1 2004/09/30 15:10:44 poppnk Exp $
#

DISTNAME=		chromium-src-0.9.12
PKGNAME=		chromium-0.9.12
CATEGORIES=		wip
MASTER_SITES=		http://www.reptilelabour.com/software/files/chromium/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.reptilelabour.com/software/chromium/
COMMENT=		Fast paced, arcade-style, top-scrolling space shooter

DEPENDS=		chromium-data>=0.9:../../wip/chromium-data

WRKSRC=		${WRKDIR}/Chromium-0.9
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ENV+= HOME=${PREFIX}
CONFIGURE_ARGS+=--disable-setup

do-install:
	${INSTALL_GAME} ${WRKSRC}/bin/chromium \
		${PREFIX}/bin/chromium-bin
	${ECHO} "#!/bin/sh" > ${WRKSRC}/bin/chromium.sh
	${ECHO} env CHROMIUM_DATA=${PREFIX}/share/chromium/ chromium-bin \
		>> ${WRKSRC}/bin/chromium.sh
	${INSTALL_SCRIPT} ${WRKSRC}/bin/chromium.sh \
		${PREFIX}/bin/chromium

.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
