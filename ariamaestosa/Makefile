# $NetBSD: Makefile,v 1.4 2012/10/31 01:47:38 asau Exp $
#

DISTNAME=	AriaSrc-1.4.5
PKGNAME=	${DISTNAME:S/Src/Maestosa/}
CATEGORIES=	audio
MASTER_SITES=	http://sourceforge.net/projects/ariamaestosa/files/ariamaestosa/1.4.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ariamaestosa.sourceforge.net/
COMMENT=	Open-source (GPL) midi tracker/editor
#LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND public-domain

BUILD_DEPENDS+=		scons-[0-9]*:../../devel/scons

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++
USE_TOOLS+=		pkg-config

do-build:
			cd ${WRKSRC} && \
			${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
#.include "../../audio/jack/buildlink3.mk" # jack build is broken on NetBSD
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
