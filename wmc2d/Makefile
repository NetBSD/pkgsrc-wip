# $NetBSD: Makefile,v 1.3 2012/11/15 21:24:26 othyro Exp $
#

DISTNAME=	wmc2d-2011-04-29-17
PKGNAME=	wmc2d-2.05
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wmc2d/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wmc2d.sourceforge.net/
COMMENT=	Dockapp to monitor coretemp temperature and cpufreq frequency
LICENSE=	gnu-agpl-v3

USE_TOOLS+=		gmake
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

WRKSRC=			${WRKDIR}/wmc2d

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-build
SUBST_MESSAGE.paths=	Fixing PREFIX and PKGMANDIR paths.
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e "s|/usr/local|${DESTDIR}${PREFIX}|g"
SUBST_SED.paths+=	-e "s|share/man|${PKGMANDIR}|1"

.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util036/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
