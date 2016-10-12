# $NetBSD: Makefile,v 1.17 2016/09/19 13:04:27 wiz Exp $

DISTNAME=	greenbone-security-assistant-6.0.11
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2363/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Manager for OpenVAS
LICENSE=	gnu-gpl-v2

USE_CMAKE=	YES
BUILD_DEFS+=	VARBASE
USE_LANGUAGES=	c++ c
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DLOCALSTATEDIR:PATH=${VARBASE}

BUILDLINK_TRANSFORM+=	rm:-Werror # Redefinition of macros

EGDIR=		${PREFIX}/share/examples/greenbone-security-assistant

MAKE_DIRS=	${PKG_SYSCONFDIR}/openvas

CONF_FILES+=	${EGDIR}/gsad_log.conf ${PKG_SYSCONFDIR}/openvas/gsad_log.conf

SUBST_CLASSES+=		confdir
SUBST_FILES.confdir=	CMakeLists.txt
SUBST_SED.confdir=	-e 's,DESTINATION $${GSA_CONFIG_DIR},DESTINATION ${EGDIR}/,'
SUBST_STAGE.confdir=	post-patch

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../wip/openvas-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
