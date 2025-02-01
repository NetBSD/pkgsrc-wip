# $NetBSD: Makefile,v 1.24 2019/04/26 14:12:35 maya Exp $

DISTNAME=	weewx-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	misc
MASTER_SITES=	https://weewx.com/downloads/released_versions/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://weewx.com/
COMMENT=	Python-powered template engine and code-generator
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=

# weewx uses sqlite3
.include "../../lang/python/batteries-included.mk"

TOOL_DEPENDS+=  ${PYPKGPREFIX}-poetry>=0.12:../../devel/py-poetry

# pyproject.toml, in order:
DEPENDS+=	${PYPKGPREFIX}-configobj>=5.0:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-CT3>=3.1:../../wip/py-CT3 # textproc
DEPENDS+=	${PYPKGPREFIX}-Pillow>=5.2:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-ephem>=3.7.6.0:../../math/py-ephem
DEPENDS+=	${PYPKGPREFIX}-pymysql>=1.0:../../databases/py-pymysql
DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-usb>=1.0.2:../../devel/py-usb

REPLACE_PYTHON+=		src/weewx_data/util/i18n/i18n-report

# Ignore perl rather than depend on it.  For now, don't even consider
# a split package.
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/weewx_data/util/logwatch/scripts/services/weewx

DOCDIR=		${PREFIX}/share/doc/weewx

INSTALLATION_DIRS=	${DOCDIR}
post-install:
	${MV} ${DESTDIR}/${PREFIX}/${PYSITELIB}/LICENSE.txt ${DESTDIR}${DOCDIR}
	${MV} ${DESTDIR}/${PREFIX}/${PYSITELIB}/README.md ${DESTDIR}${DOCDIR}

# \todo Grasp and perhaps deal with config file generation/update.

# \todo Consider how to manage edits to skins, which are sort of code
# and sort of config files.

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
