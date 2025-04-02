#	$NetBSD$

.include "../../databases/sqlite3/Makefile.common"

DISTNAME=	sqlite-src-${SQLITE3_DISTVERSION}
PKGNAME=	sqlite3-test-${SQLITE3_VERSION}
CATEGORIES=	databases
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Package for running sqlite3 automatic tests

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# none
CHECK_PERMS=	no

USE_LANGUAGES+=	c

do-test:
	${RUN}cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} ${TCLSH} ${WRKSRC}/test/testrunner.tcl mdevtest \
		--jobs ${MAKE_JOBS:U1}

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3-${SQLITE3_VERSION}{,nb*}
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
