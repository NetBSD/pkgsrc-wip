# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	3.0.6
PKGNAME=	cinnamon-nemo-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=/linuxmint/nemo/archive/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/nemo
COMMENT=	File Manager for Cinnamon
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/nemo-${DISTNAME}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake bash pkg-config automake intltool

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fix python shebang
SUBST_FILES.python=	data/merge_action_strings
SUBST_STAGE.python=	pre-install
SUBST_SED.python+=	-e 's|/usr/bin/python2|${PYTHONBIN}|g'

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
BUILD_DEPENDS+=	gnome-common-[0-9]*:../../devel/gnome-common

.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/cinnamon-desktop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
