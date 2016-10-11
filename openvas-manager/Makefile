# $NetBSD: Makefile,v 1.17 2016/09/19 13:04:27 wiz Exp $

DISTNAME=	openvas-manager-6.0.9
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2359/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Manager for OpenVAS
LICENSE=	gnu-gpl-v2

USE_CMAKE=	YES
BUILD_DEFS+=	VARBASE
USE_LANGUAGES=	c++ c
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DLOCALSTATEDIR:PATH=${VARBASE}

REPLACE_PYTHON+=	tools/extra/xml_split

EGDIR=		${PREFIX}/share/examples/openvas-manager

OWN_DIRS=	${PKG_SYSCONFDIR}/openvas

CONF_FILES+=	${EGDIR}/openvasmd_log.conf ${PKG_SYSCONFDIR}/openvas/openvasmd_log.conf
CONF_FILES+=	${EGDIR}/pwpolicy.conf ${PKG_SYSCONFDIR}/openvas/pwpolicy.conf

SUBST_CLASSES+=		confdir
SUBST_FILES.confdir=	CMakeLists.txt
SUBST_SED.confdir=	-e 's,DESTINATION $${OPENVAS_SYSCONF_DIR},DESTINATION ${EGDIR}/,'
SUBST_STAGE.confdir=	post-patch

.include "../../lang/python/application.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/openvas-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
