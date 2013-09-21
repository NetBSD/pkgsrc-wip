# $NetBSD: Makefile,v 1.5 2013/09/21 12:13:58 othyro Exp $
#

DISTNAME=	amqplib-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/a/amqplib/
FETCH_USING=	curl
EXTRACT_SUFX=	.tgz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://barryp.org/software/py-amqplib/
COMMENT=	Client library for AMQP written by python
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

PYDISTUTILSPKG=		yes

INSTALLATION_DIRS=	share/doc/py-amqplib

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DESTDIR}${PREFIX}/share/doc/py-amqplib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
