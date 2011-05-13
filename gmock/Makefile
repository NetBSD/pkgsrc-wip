# $NetBSD: Makefile,v 1.2 2011/05/13 10:33:52 ryo-on Exp $
#

DISTNAME=	gmock-1.6.0
CATEGORIES=	devel
MASTER_SITES=	http://googlemock.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/googlemock/
COMMENT=	C++ Mocking Framework
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_LIBTOOL=	yes

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing dynamic python
SUBST_FILES.fix-python+=	gtest/scripts/*py
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

CONFIGURE_ARGS+=	--enable-external-gtest

pre-configure:
	${RM} -r ${WRKSRC}/gtest
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gmock-config ${DESTDIR}${PREFIX}/bin

.include "../../wip/gtest/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
