# $NetBSD$

DISTNAME=	lcov-${LCOV_FULL}
LCOV_VERSION=	1
LCOV_RELEASE=	12
LCOV_FULL=	${LCOV_VERSION}.${LCOV_RELEASE}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=linux-test-project/}

GIT_REPOSITORIES=	lcov
GIT_REPO.lcov=		https://github.com/linux-test-project/lcov.git
WRKSRC=			${WRKDIR}/lcov

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/linux-test-project/lcov/
COMMENT=	Extension of GCOV
LICENSE=	gnu-gpl-v2

EGDIR=		${PREFIX}/share/examples/lcov
CONF_FILES+=	${EGDIR}/lcovrc ${PKG_SYSCONFDIR}/lcovrc

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFG_DIR=${EGDIR}
MAKE_FLAGS+=	MAN_DIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	VERSION=${LCOV_VERSION}
MAKE_FLAGS+=	RELEASE=${LCOV_RELEASE}
MAKE_FLAGS+=	FULL=${LCOV_FULL}

REPLACE_PERL+=	bin/gendesc
REPLACE_PERL+=	bin/genhtml
REPLACE_PERL+=	bin/geninfo
REPLACE_PERL+=	bin/genpng
REPLACE_PERL+=	bin/lcov
REPLACE_PERL+=	bin/updateversion.pl

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
