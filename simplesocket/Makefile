# $NetBSD$

DISTNAME=		simplesocket-0.0.0.20240102
CATEGORIES=		net devel
MASTER_SITES+=		${MASTER_SITE_GITHUB:=ahupowerdns/}
GITHUB_TAG=		3af5e1d449128d0f3cc80774d8ab72dfc95c35c8

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/ahupowerdns/simplesocket/commits/master/
COMMENT=		Simple socket helpers for C++ 2014
LICENSE=		mit

USE_LANGUAGES=		c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS+=	include lib lib/pkgconfig

SUBST_CLASSES+=		prefix
SUBST_VARS.prefix+=	PREFIX
SUBST_FILES.prefix=	simplesockets.pc
SUBST_STAGE.prefix=	post-configure
SUBST_MESSAGE.prefix=	Fix installation prefix in pkg-config file.

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.hh ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/simplesockets.pc ${DESTDIR}${PREFIX}/lib/pkgconfig
	${INSTALL_LIB} ${WRKSRC}/output/libsimplesockets.so ${DESTDIR}${PREFIX}/lib

post-extract:
	${CP} ${FILESDIR}/simplesockets.pc ${WRKSRC}

# segfaults because address ::1:10000 already in use?
do-test:
	cd ${WRKSRC}/output && ${SETENV} ${MAKE_ENV} ./testrunner

.include "../../devel/meson/build.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
