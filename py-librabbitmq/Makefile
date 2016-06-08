# $NetBSD: Makefile,v 1.1 2014/09/22 01:33:50 othyro Exp $

DISTNAME=	librabbitmq-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/librabbitmq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/celery/librabbitmq
COMMENT=	AMQP Client using the rabbitmq-c library
LICENSE=	gnu-gpl-v2 AND mpl-1.1

DEPENDS+=	${PYPKGPREFIX}-amqp>=1.2.1:../../net/py-amqp

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gawk gmake gsed pkg-config

CONFIGURE_DIRS+=	clib
PKGCONFIG_OVERRIDE+=	clib/librabbitmq.pc.in

REPLACE_PYTHON=	funtests/setup.py

.include "options.mk"

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/funtests

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
