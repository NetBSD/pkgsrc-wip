# $NetBSD: Makefile,v 1.6 2009/08/31 22:10:25 thomasklausner Exp $
#

DISTNAME=		chromium-src-0.9.12
PKGNAME=		chromium-0.9.12
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www.reptilelabour.com/software/files/chromium/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.reptilelabour.com/software/chromium/
COMMENT=		Fast paced, arcade-style, top-scrolling space shooter

DEPENDS=		chromium-data>=0.9:../../wip/chromium-data

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Chromium-0.9
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash
CONFIG_SHELL=		${TOOLS_PREFIX.bash}/bin/bash
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		HOME=${PREFIX:Q}
CONFIGURE_ARGS+=	--disable-setup
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

do-install:
	${INSTALL_GAME} ${WRKSRC}/bin/chromium \
		${DESTDIR}${PREFIX}/bin/chromium-bin
	${ECHO} "#!/bin/sh" > ${WRKSRC}/bin/chromium.sh
	${ECHO} env CHROMIUM_DATA=${PREFIX}/share/chromium/ chromium-bin \
		>> ${WRKSRC}/bin/chromium.sh
	${INSTALL_SCRIPT} ${WRKSRC}/bin/chromium.sh \
		${DESTDIR}${PREFIX}/bin/chromium

#.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
