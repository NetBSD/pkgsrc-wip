# $NetBSD: Makefile,v 1.1.1.1 2011/05/12 11:50:56 ryo-on Exp $
#

DISTNAME=	gtest-1.6.0
CATEGORIES=	devel
MASTER_SITES=	http://googletest.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/googletest/
COMMENT=	Google C++ Testing Framework
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_LIBTOOL=	yes

SUBST_CLASSES+=		fix-python
SUBST_STAGE.fix-python=	pre-configure
SUBST_MESSAGE.fix-python=	Fixing dynamic python
SUBST_FILES.fix-python+=	scripts/*py
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gtest-config ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
