# $NetBSD: Makefile,v 1.7 2012/09/28 23:21:49 asau Exp $

CRYSTAL_VERSION=	3.0.4
DISTNAME=		fvwm-crystal-${CRYSTAL_VERSION}
CATEGORIES=		wm
MASTER_SITES=		http://download.gna.org/fvwm-crystal/${CRYSTAL_VERSION}/
PKGREVISION=		2

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		http://fvwm-crystal.org/
COMMENT=		Easy to use, powerful desktop environment


EGDIR=			${PREFIX}/share/examples/fvwm-crystal

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_FILES.python=	bin/fvwm-crystal.apps bin/fvwm-crystal.wallpaper \
			fvwm/scripts/FvwmMPD/getprevdir.py fvwm/scripts/FvwmMPD/stripnames.py
SUBST_SED.python=	-e "s,/usr/bin/env python,${PYTHONBIN},g"
SUBST_MESSAGE.python=	Fixing harcoded python path

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-patch
SUBST_FILES.bash=	fvwm/scripts/FvwmMPD/getdir.sh fvwm/scripts/FvwmMPD/listsongs.sh \
			fvwm/scripts/FvwmMPD/parseplaylist.sh
SUBST_SED.bash=		-e "s,/usr/bin/env bash,${PREFIX}/bin/bash,g"
SUBST_MESSAGE.bash=	Fixing harcoded bash path


DEPENDS+=	fvwm>=2.5.14:../../wm/fvwm-devel
DEPENDS+=	trayer>=1.0:../../wm/trayer
DEPENDS+=	ImageMagick>=6.2.9.1:../../graphics/ImageMagick
DEPENDS+=	bash>=3.0:../../shells/bash
.include "options.mk"


do-build:
	#cd ${WRKSRC} && prefix=${WRKSRC}/build make install # for generating PLIST

do-install:
	cd ${WRKSRC} && prefix=${PREFIX} make install

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/addons/Xresources ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/addons/Xsession ${EGDIR}


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
