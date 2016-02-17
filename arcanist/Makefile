# $NetBSD$

PKGNAME=		arcanist-0
CATEGORIES=		devel

GIT_REPOSITORIES=	arcanist
GIT_REPO.arcanist=	https://github.com/phacility/arcanist.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=phacility/arcanist/}
COMMENT=	Command line interface for Phabricator
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/arcanist

USE_TOOLS+=	bash

DEPENDS=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS=	libphutil-[0-9]*:../../wip/libphutil

REPLACE_BASH+=	bin/arc

SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	scripts/arcanist.php
SUBST_FILES.php+=	scripts/hgdaemon/hgdaemon_client.php
SUBST_FILES.php+=	scripts/hgdaemon/hgdaemon_server.php
SUBST_FILES.php+=	src/lint/linter/xhpast/rules/__tests__/inline-html/inline-html.lint-test
SUBST_SED.php=		-e 's,/usr/bin/env php,${PREFIX}/bin/php,'

REPLACE_PYTHON+=	scripts/breakout.py

NO_BUILD=	yes

ARCANISTDIR=	${PREFIX}/share/arcanist

AUTO_MKDIRS=	yes

do-install:
	${RUN} cp -r ${WRKSRC}/* ${DESTDIR}${ARCANISTDIR}
	${RUN} ${LN} -s ${ARCANISTDIR}/bin/arc \
		${DESTDIR}${PREFIX}/bin/arc

DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl

.include "../../wip/mk/git-package.mk"
.include "../../lang/python/application.mk"
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
