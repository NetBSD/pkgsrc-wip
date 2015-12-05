# $NetBSD$

PKGNAME=		arcanist-0
CATEGORIES=		devel

GIT_REPOSITORIES=	arcanist
GIT_REPO.arcanist=	git@github.com:phacility/arcanist.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=phacility/arcanist/}
COMMENT=	Command line interface for Phabricator
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/arcanist

USE_TOOLS+=	bash

DEPENDS=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl

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
#	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${ARCANISTDIR}
	${RUN} cp -r ${WRKSRC}/* ${DESTDIR}${ARCANISTDIR}
#	${RUN} ${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${RUN} ${LN} -s ${ARCANISTDIR}/scripts/arcanist.php \
		${DESTDIR}${PREFIX}/bin/arc

.include "../../wip/mk/git-package.mk"
.include "../../lang/python/application.mk"
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
