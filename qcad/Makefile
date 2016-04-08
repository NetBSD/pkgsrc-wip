# $NetBSD: Makefile,v 1.61 2015/04/25 14:20:27 tnn Exp $
#

DISTNAME=	qcad-3.13.1.3
.include "./Makefile.common"
COMMENT=	2D CAD system
# See License.txt for info
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoconf gmake pax
# Possible: bsdtar, gtar, nbtar, pax
# Default: nbtar
EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
# BROKEN=		libtool handling is NOT correct

BUILD_TARGET=	all

MAKE_ENV+=	QMAKESPEC=${QTDIR}/mkspecs/default
PREPEND_PATH+=	${QTDIR}/bin
LDFLAGS+=	-lexecinfo
AUTO_MKDIRS=	yes

# I really want this to be post-*patch* where it makes sense, but QTDIR isn't
# available until after the wrapper phase because it depends on
# BUILDLINK_PREFIX.qt3-libs, which buildlink3 sets.  Nothing is easy.  :) The
# patches have replaced old hardcoded paths with fixed cookies @PREFIX@ and
# @QTDIR@.  The SUBST framework will replace the cookies with the proper
# values.
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Attending to hard-coded paths.
SUBST_FILES.paths+=	qcadlib/src/engine/rs_system.cpp
SUBST_FILES.paths+=	qcad/src/qc_applicationwindow.cpp
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@QTDIR@,${QTDIR},g'

REPLACE_BASH=		support/ecmagenerator/generate.sh
INSTALLATION_DIRS=	bin share/qcad

# http://www.qcad.org/en/component/content/article/78-qcad/111-qcad-compilation-from-sources
do-configure:
	cd ${WRKSRC}  && \
	env ${PKGSRC_ENV} ${CONFIGURE_ENV} QTDIR=${QTDIR} ${QTDIR}/bin/qmake -r

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/release/qcad-bin ${DESTDIR}${PREFIX}/bin/qcad
	cd ${WRKSRC} && umask 022 && \
	pax -rwpm support examples fonts patterns scripts ${DESTDIR}${PREFIX}/share/qcad

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.7
.include "../../x11/qt4-tools/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.7
BUILDLINK_DEPMETHOD.qt4-tools=	full # uses assistant for help
.include "../../mk/bsd.pkg.mk"
