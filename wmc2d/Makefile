# $NetBSD: Makefile,v 1.7 2013/03/04 21:58:38 thomasklausner Exp $

DISTNAME=	wmc2d-2011-04-29-17
PKGNAME=	wmc2d-2.05
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wmc2d/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wmc2d.sourceforge.net/
COMMENT=	Dockapp to monitor coretemp temperature and cpufreq frequency
LICENSE=	gnu-agpl-v3

BUILD_DEPENDS+=		libxcb-[0-9]*:../../x11/libxcb

USE_TOOLS+=		gmake pkg-config
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

WRKSRC=			${WRKDIR}/wmc2d

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-build
SUBST_MESSAGE.paths=	Fixing PREFIX and PKGMANDIR paths.
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e "s|/usr/local|${DESTDIR}${PREFIX}|g"
SUBST_SED.paths+=	-e "s|share/man|${PKGMANDIR}|1"

.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
