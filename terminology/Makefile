# $NetBSD: Makefile,v 0.2 2018/09/06 16:15:10 andyb Exp $

DISTNAME=	terminology-1.7.0
CATEGORIES=	x11
PKGREVISION=	1
MASTER_SITES=	https://download.enlightenment.org/rel/apps/terminology/
EXTRACT_SUFX=	.tar.xz
DISTFILES=	${DEFAULT_DISTFILES}

VERSION=		1.7.0
THEMES_BIN=		v${VERSION}.tar.gz
DISTFILES+=		${THEMES_BIN}
SITES.${THEMES_BIN}=	${MASTER_SITE_GITHUB:=kikadf/}terminology-themes/archive/
THEMES_WRKSRC=		${WRKDIR}/terminology-themes-${VERSION}
THEMES_DIR=		${DESTDIR}${PREFIX}/share/${PKGBASE}/themes/
INSTALLATION_DIRS+=	share/${PKGBASE}/themes

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://www.enlightenment.org/about-terminology
COMMENT=	Enlightenment terminal
LICENSE=	2-clause-bsd

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool

SUBST_CLASSES+=			workaround
SUBST_STAGE.workaround=		pre-configure
SUBST_MESSAGE.workaround=	Ugly workaround to fix random edje_cc hang on build: \
				disable theme compiling, use prebuilded themes.
SUBST_FILES.workaround=		data/meson.build
SUBST_SED.workaround=		-e "s,subdir('themes'),\#subdir('themes'),g"

post-install:
	${INSTALL_DATA} ${THEMES_WRKSRC}/themes/*.edj ${THEMES_DIR}
	${INSTALL_DATA} ${THEMES_WRKSRC}/themes/nyanology/*.edj ${THEMES_DIR}

.include "../../devel/meson/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/efl-current/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
