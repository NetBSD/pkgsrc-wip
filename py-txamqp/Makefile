# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	python-txamqp_0.3.orig
PKGNAME=	${PYPKGPREFIX}-txamqp-0.3
CATEGORIES=	net
MASTER_SITES=	http://launchpadlibrarian.net/30388120/

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	http://launchpad.net/txamqp/
COMMENT=	Python library for communicating with AMQP using Twisted
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_LANGUAGES=	# none

WRKSRC=		${WRKDIR}/python-txamqp-0.3
EGG_NAME=	txAMQP-${PKGVERSION_NOREV}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
