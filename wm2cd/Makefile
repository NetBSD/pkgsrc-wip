# $NetBSD: Makefile,v 1.1.1.1 2012/04/24 15:50:24 othyro Exp $
#

DISTNAME=	wmc2d-2010-08-16-13
PKGNAME=	wmc2d-2.04
CATEGORIES=	wm
MASTER_SITES=	http://www.goron.de/~johns/wmc2d/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.goron.de/~johns/wmc2d/
COMMENT=	Dockapp to monitor coretemp temperature and cpufreq frequency
LICENSE=	gnu-agpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=		gmake
INSTALLATION_DIRS+=	bin

WRKSRC=	${WRKDIR}/wmc2d

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-build
SUBST_MESSAGE.prefix=	Fixing prefix path.
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e "s,/usr/local/bin,${DESTDIR}${PREFIX}/bin,"

.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
