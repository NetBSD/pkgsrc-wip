# $NetBSD: Makefile,v 1.2 2010/09/13 02:05:26 rxg Exp $

DISTNAME=	chromium.r58671
PKGNAME=	chromium-7.0.518.0
CATEGORIES=	www
MASTER_SITES=	http://chromium-browser-source.commondatastorage.googleapis.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://dev.chromium.org/Home
COMMENT=	Open-source browser project
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/home/chrome-svn/tarball/chromium/src

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

CHECK_PORTABILITY_SKIP+=breakpad/src/third_party/protobuf/protobuf/post_process_dist.sh
CHECK_PORTABILITY_SKIP+=native_client/src/third_party/libxt/configure
CHECK_PORTABILITY_SKIP+=third_party/protobuf2/src/post_process_dist.sh
CHECK_PORTABILITY_SKIP+=third_party/xdg-utils/scripts/xdg-terminal
CHECK_PORTABILITY_SKIP+=third_party/xdg-utils/scripts/xdg-terminal.in
CHECK_PORTABILITY_SKIP+=third_party/GTM/BuildScripts/BuildAllSDKs.sh
CHECK_PORTABILITY_SKIP+=v8/tools/linux-tick-processor

SUBST_CLASSES+=		path
SUBST_FILES.path=	build/common.gypi build/linux/python_arch.sh chrome/chrome_tests.gypi
SUBST_STAGE.path=	post-patch
SUBST_SED.path+=	-e 's|/usr/lib/libpython<(python_ver)|${LOCALBASE}/${PYLIB}|'
SUBST_SED.path+=	-e 's|/bin/bash|${LOCALBASE}/bin/bash|'
SUBST_SED.path+=	-e 's|/usr/include/python<(python_ver)|${LOCALBASE}/${PYINC}|'
SUBST_SED.path+=	-e 's|-lpython<(python_ver)|-lpython${PYVERSSUFFIX}|'

post-extract:
	${FIND} ${WRKSRC} -type d -name '.svn' | ${XARGS} ${RM} -rf

pre-configure:
	${LN} -sf ${PYTHONBIN} ${TOOLS_DIR}/bin/python

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} python build/gyp_chromium

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
