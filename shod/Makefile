# $NetBSD$

DISTNAME=	shod-0.3.2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=phillbush/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-usesr@NetBSD.org
HOMEPAGE=	https://github.com/phillbush/shod/
COMMENT=	Hybrid (floating and tiling) tabbed window manager
LICENSE=	mit

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	config.mk
SUBST_SED.prefix+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.prefix+=	-e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.prefix+=	-e 's,share/man,${PKGMANDIR},g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shod ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shod.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

DEPENDS+=	wmctrl-[0-9]*:../../wm/wmctrl
DEPENDS+=	sxhkd-[0-9]*:../../x11/sxhkd

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
