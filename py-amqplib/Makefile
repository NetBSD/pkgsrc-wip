# $NetBSD: Makefile,v 1.3 2012/01/30 05:53:23 noud4 Exp $
#

DISTNAME=	amqplib-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/a/amqplib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://barryp.org/software/py-amqplib/
COMMENT=	Client library for AMQP wirtten by python
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=		yes

INSTALLATION_DIRS=	share/doc/py-amqplib

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DESTDIR}${PREFIX}/share/doc/py-amqplib

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
