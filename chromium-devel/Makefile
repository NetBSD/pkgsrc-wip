# $NetBSD: Makefile,v 1.6 2010/09/28 05:13:34 rxg Exp $

DISTNAME=	chromium-7.0.518.0
CATEGORIES=	www
MASTER_SITES=	http://build.chromium.org/buildbot/official/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://dev.chromium.org/Home
COMMENT=	Open-source browser project
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

# Override the LINK variable for the platforms which do not have flock(1).
MAKE_ENV+=	LINK=${CXX}

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=	GYP_DEFINES=${GYP_DEFINES:Q}
.if ${OPSYS} == "NetBSD"
GYP_DEFINES+=	OS=netbsd
# Enable this will cause the infinite loop when mksnapshot generates snapshot.cc
GYP_DEFINES+=	v8_use_snapshot=0
.endif
GYP_DEFINES+=	use_system_libevent=1
GYP_DEFINES+=	use_system_libjpeg=1
GYP_DEFINES+=	use_system_libxml=1

RESTRICTED=	tarball contains some allegedly patent-infringing source code
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

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

pre-configure:
	${LN} -sf ${PYTHONBIN} ${TOOLS_DIR}/bin/python

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} python build/gyp_chromium --depth=${WRKSRC}

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
