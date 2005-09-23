# $NetBSD: Makefile,v 1.4 2005/09/23 07:03:27 rillig Exp $

DISTNAME=	Zope-3.1.0c3
PKGNAME=	zope3-unstable-3.1.0c3
CATEGORIES=	wip www
MASTER_SITES=	http://www.zope.org/Products/Zope3/3.1.0c3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ykomatsu@akaumigame.org
HOMEPAGE=	http://dev.zope.org/Zope3/
COMMENT=	Zope 3 Application Server

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-python ${PYTHONBIN} \
		--prefix ${PREFIX}/share/zope3 \
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

MESSAGE_SUBST+=	ZOPE3_USER=${ZOPE3_USER} ZOPE3_GROUP=${ZOPE3_GROUP}

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -type f -print | ${XARGS} ${RM} -f

post-install:
	${LN} -s ${PREFIX}/share/zope3/bin/mkzeoinstance ${PREFIX}/bin
	${LN} -s ${PREFIX}/share/zope3/bin/mkzopeinstance ${PREFIX}/bin
	${LN} -s ${PREFIX}/share/zope3/bin/zopetest ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
