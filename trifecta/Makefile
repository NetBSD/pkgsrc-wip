# $NetBSD$

DISTNAME=		trifecta-0.0.0.20240204
CATEGORIES=		www graphics
MASTER_SITES+=		${MASTER_SITE_GITHUB:=berthubert/}
GITHUB_TAG=		40491d40f1c7946bc6f8e3148d0431e222f67fa8

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://berthub.eu/articles/trifecta
COMMENT=		Educational image sharing website
LICENSE=		mit

USE_LANGUAGES=		c++
# cmake for doctest detection, which doesn't provide a pkg-config file
USE_TOOLS+=		cmake pkg-config

CXXFLAGS+=		-I${BUILDLINK_PREFIX.doctest}/include/doctest

INSTALLATION_DIRS+=	bin share/doc/trifecta

do-test:
	cd ${WRKSRC}/output && ${SETENV} ${MAKE_ENV} ./testrunner

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/trifecta ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/trifecta

.include "../../devel/meson/build.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../wip/argparse/buildlink3.mk"
.include "../../wip/bcryptcpp/buildlink3.mk"
.include "../../wip/doctest/buildlink3.mk"
.include "../../wip/simplesocket/buildlink3.mk"
.include "../../wip/sqlitewrite/buildlink3.mk"
.include "../../www/cpp-httplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
