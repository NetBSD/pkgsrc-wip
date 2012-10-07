# $NetBSD: Makefile,v 1.6 2012/10/07 11:54:46 asau Exp $
#

DISTNAME=	jabberbot-0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	http://thp.io/2007/python-jabberbot/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Module to enable easy creation of XMPP bots in Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-xmpppy>=0.5.0rc1:../../wip/py-xmpppy

USE_LANGUAGES=	# none

PYDISTUTILSPKG=		yes

EXDIR=		${PREFIX}/share/examples/py-jabberbot

INSTALLATION_DIRS+=	${EXDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${EXDIR}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
