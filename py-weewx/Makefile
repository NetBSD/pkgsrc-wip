# $NetBSD: Makefile,v 1.24 2019/04/26 14:12:35 maya Exp $

DISTNAME=	weewx-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://weewx.com/downloads/released_versions/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://weewx.com/
COMMENT=	Python-powered template engine and code-generator
LICENSE=	gnu-gpl-v3

# This package is intended to be usable with the most recent stable
# branch; modifications should either be tested in that environment or
# sent to ${MAINTAINER}.

USE_LANGUAGES=

# weewx uses sqlite3
.include "../../lang/python/batteries-included.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry>=0.12:../../devel/py-poetry

# pyproject.toml, in order:
DEPENDS+=	${PYPKGPREFIX}-configobj>=5.0:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-CT3>=3.1:../../wip/py-CT3 # textproc
DEPENDS+=	${PYPKGPREFIX}-Pillow>=5.2:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-ephem>=3.7.6.0:../../math/py-ephem
DEPENDS+=	${PYPKGPREFIX}-pymysql>=1.0:../../databases/py-pymysql
DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-usb>=1.0.2:../../devel/py-usb

# Dependencies of common extensions, as long as they are not heavy.
#   mqtt
DEPENDS+=	${PYPKGPREFIX}-paho-mqtt>=2:../../net/py-paho-mqtt

REPLACE_PYTHON+=	src/weewx_data/util/i18n/i18n-report

# Ignore perl rather than depend on it.  For now, don't even consider
# a split package.
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/weewx_data/util/logwatch/scripts/services/weewx

DOCDIR=			${PREFIX}/share/doc/weewx-${PYVERSSUFFIX}

INSTALLATION_DIRS=	${DOCDIR}

# weewx 4.x had code and data in the same dir, and setup.py install
# would merge config file changes.  weewx 5.x does not appear to do
# this, and the user is left to manually adjust or not, as is the
# usual custom.  This comment is a caution that the config file
# behavior is not entirely understood.  This also applies to skins.

post-install:
	${RM} -f ${DESTDIR}/${PREFIX}/${PYSITELIB}/LICENSE.txt
	${RM} -f ${DESTDIR}/${PREFIX}/${PYSITELIB}/README.md
	cd ${DESTDIR}${PREFIX}/bin && ${MV} weectl weectl-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} weewxd weewxd-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
