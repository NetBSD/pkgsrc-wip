# $NetBSD: Makefile,v 1.1.1.1 2006/08/31 10:19:33 milosn Exp $

CRYSTAL_VERSION=	3.0.4
DISTNAME=		fvwm-crystal-${CRYSTAL_VERSION}
CATEGORIES=		wm
MASTER_SITES=		http://download.gna.org/fvwm-crystal/${CRYSTAL_VERSION}/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		http://fvwm-crystal.org/
COMMENT=                Easy to use, powerful desktop environment


EGDIR=		${PREFIX}/share/examples/fvwm-crystal


SUBST_CLASSES=		python bash

SUBST_STAGE.python=	post-patch
SUBST_FILES.python=	bin/fvwm-crystal.apps bin/fvwm-crystal.wallpaper \
			fvwm/scripts/FvwmMPD/getprevdir.py fvwm/scripts/FvwmMPD/stripnames.py
SUBST_SED.python=	-e "s,/usr/bin/env python,${PREFIX}/bin/python${PYVERSSUFFIX},g"
SUBST_MESSAGE.python=	"Fixing harcoded python path"

SUBST_STAGE.bash=	post-patch
SUBST_FILES.bash=	fvwm/scripts/FvwmMPD/getdir.sh fvwm/scripts/FvwmMPD/listsongs.sh \
			fvwm/scripts/FvwmMPD/parseplaylist.sh
SUBST_SED.bash=		-e "s,/usr/bin/env bash,${PREFIX}/bin/bash,g"
SUBST_MESSAGE.bash=	"Fixing harcoded bash path"


DEPENDS+=	fvwm-devel>=2.5.14:../../wm/fvwm-devel
DEPENDS+=	trayer>=1.0:../../wip/trayer
DEPENDS+=	ImageMagick>=6.2.9.1:../../graphics/ImageMagick
DEPENDS+=	hsetroot>=1.0.2:../../x11/hsetroot
DEPENDS+=	aterm>=1.0.0:../../x11/aterm
DEPENDS+=	bash>=3.0:../../shells/bash
DEPENDS+=	musicpd>=0.11.5:../../audio/musicpd
DEPENDS+=	mpc>=0.11.2:../../audio/mpc


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
