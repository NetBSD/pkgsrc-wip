# $NetBSD: Makefile,v 1.11 2013/05/04 01:41:49 othyro Exp $
#

DISTNAME=	AriaSrc-1.4.5
PKGNAME=	${DISTNAME:S/Src/Maestosa/}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ariamaestosa/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ariamaestosa.sourceforge.net/
COMMENT=	Open-source (GPL) midi tracker/editor
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND public-domain

BUILD_DEPENDS+=		scons-[0-9]*:../../devel/scons
BUILD_DEPENDS+=		irrxml-1.2:../../wip/irrxml

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++
USE_TOOLS+=		chmod pkg-config
INSTALLATION_DIRS+=	share/applications

.include "options.mk"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
	cd ${WRKSRC} && \
		${SETENV} ${INSTALL_ENV} ${PREFIX}/bin/scons install prefix=${DESTDIR}${PREFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/Freedesktop/Aria.desktop ${DESTDIR}${PREFIX}/share/applications/
	${CHMOD} g-w ${DESTDIR}${PREFIX}/bin/Aria
	${CHMOD} -R g-w ${DESTDIR}${PREFIX}/share/Aria

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
