# $NetBSD$

DISTNAME=		sqlitewrite-0.0.0.20240122
CATEGORIES=		databases devel
MASTER_SITES+=		${MASTER_SITE_GITHUB:=berthubert/}
GITHUB_TAG=		05b95d9540047078cc591367792d4a78f03b930c

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/berthubert/sqlitewrite/
COMMENT=		CSV-like storage to sqlite
LICENSE=		mit

USE_LANGUAGES=		c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS+=	include lib lib/pkgconfig

SUBST_CLASSES+=		prefix
SUBST_VARS.prefix+=	PREFIX
SUBST_FILES.prefix=	sqlitewrite.pc
SUBST_STAGE.prefix=	post-configure
SUBST_MESSAGE.prefix=	Fix installation prefix in pkg-config file.

do-install:
	${INSTALL_DATA} ${WRKSRC}/jsonhelper.hh ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sqlwriter.hh ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sqlitewrite.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/sqlitewriter.pc
	${INSTALL_LIB} ${WRKSRC}/output/libsqlitewriter.so ${DESTDIR}${PREFIX}/lib

post-extract:
	${CP} ${FILESDIR}/sqlitewrite.pc ${WRKSRC}

do-test:
	cd ${WRKSRC}/output && ${SETENV} ${MAKE_ENV} ./testrunner

#.include "../../devel/cmake/build.mk"
.include "../../devel/meson/build.mk"
.include "../../databases/sqlite3/buildlink3.mk"
# for tests only
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
