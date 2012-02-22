# $NetBSD: Makefile,v 1.5 2012/02/22 11:36:26 bartoszkuzma Exp $

DISTNAME=	mongodb-src-r2.0.2
PKGNAME=	${DISTNAME:S/src-r//}
CATEGORIES=	databases
MASTER_SITES=	http://downloads.mongodb.org/src

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://mongodb.org/
COMMENT=	NOSQL distributed document-oriented database
LICENSE=	gnu-agpl-v3 # Client and tools licensed under apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

BUILD_DEPENDS+=	scons:../../devel/scons

SCONS_BIN=	${PREFIX}/bin/scons
SCONS_ARGS=	${_MAKE_JOBS}
SCONS_ARGS+=	--use-system-all

# XXX No better idea how to pass CXXFLAGS and LDFLAGS to scons
SUBST_CLASSES+=		scons
SUBST_STAGE.scons=	post-patch
SUBST_FILES.scons=	SConstruct
SUBST_SED.scons=	-e "s|%PREFIX%|${PREFIX}|g"
SUBST_SED.scons+=	-e "s|%CXXFLAGS%|${CXXFLAGS}|g"
SUBST_SED.scons+=	-e "s|%LINKFLAGS%|${LDFLAGS}|g"

INSTALLATION_DIRS=	share/doc/mongodb

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS_BIN} ${SCONS_ARGS} all

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS_BIN} \
		${SCONS_ARGS} --full --prefix ${DESTDIR}${PREFIX} install

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mongodb

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-python/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/spidermonkey/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
