# $NetBSD$

DISTNAME=	fc-browse
PKGNAME=	fc-browse-0.0.20201201
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITLAB:=laemeur/fc-browse/-/raw/master/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/laemeur/fc-browse/
COMMENT=	Font browser that runs in a console window
LICENSE=	gnu-gpl-v3

DEPENDS+=	fzf-[0-9]*:../../sysutils/fzf
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	w3m-img-[0-9]*:../../www/w3m-img

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
USE_TOOLS+=	bash

REPLACE_BASH+=	fc-browse

INSTALLATION_DIRS+=	bin

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_SED.path+=	-e "s,/usr/lib,${PREFIX}/libexec,g"
SUBST_FILES.path+=	fc-browse
SUBST_MESSAGE.path=	Fixing path to helpers.

do-build:
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fc-browse ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
