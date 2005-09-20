# $NetBSD: Makefile,v 1.1.1.1 2005/09/20 03:22:15 ykomatsu Exp $

DISTNAME=	Zope-3.1.0c3
PKGNAME=	zope3-unstable-3.1.0c3
CATEGORIES=	wip www
MASTER_SITES=	http://www.zope.org/Products/Zope3/3.1.0c3/

MAINTAINER=	ykomatsu@akaumigame.org
HOMEPAGE=	http://dev.zope.org/Zope3
COMMENT=	Open source web application server

EXTRACT_SUFX=	.tgz

_ZOPE3_INSTALL_WORK=	${PREFIX}/share/zope3/.install_work

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-python ${PYTHONBIN} \
		--prefix ${_ZOPE3_INSTALL_WORK} \
		--force
BUILD_TARGET=

USE_PKGINSTALL=	yes
RCD_SCRIPTS=	zope3 zss3

ZOPE3_GROUP?=	zope3
ZOPE3_USER?=	zope3
PKG_GROUPS=	${ZOPE3_GROUP}
PKG_USERS=	${ZOPE3_USER}:${ZOPE3_GROUP}::Zope3\ user

PYTHON_VERSION_DEFAULT=		23
PYTHON_VERSION_ACCEPTED=	24 23

PLIST_SUBST+=	PYINC=${PYINC} PYLIB=${PYLIB} PYSITELIB=${PYSITELIB}
MESSAGE_SUBST+=	ZOPE3_USER=${ZOPE3_USER} ZOPE3_GROUP=${ZOPE3_GROUP}

post-install:
	${MV} ${_ZOPE3_INSTALL_WORK}/lib/python/* ${PREFIX}/${PYSITELIB}
	${MV} ${_ZOPE3_INSTALL_WORK}/include/python/* ${PREFIX}/${PYINC}
	${MV} ${_ZOPE3_INSTALL_WORK}/bin ${PREFIX}/share/zope3
	${MV} ${_ZOPE3_INSTALL_WORK}/zopeskel ${PREFIX}/share/zope3
	${RM} -R ${_ZOPE3_INSTALL_WORK}

.include "../../lang/python/application.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
