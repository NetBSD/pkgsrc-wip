# $NetBSD$

DISTNAME=	ruby-build-20250610
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rbenv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/rbenv/ruby-build/
COMMENT=	Install various Ruby versions and implementations
LICENSE=	mit

NO_BUILD=	yes

USE_TOOLS=	bash
USE_LANGUAGES=	# none

REPLACE_BASH=	bin/rbenv-install bin/rbenv-uninstall bin/ruby-build

INSTALLATION_DIRS=	bin share/ruby-build ${PKGMANDIR}/man1

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	bin/ruby-build
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	PREFIX

do-install:
	${RUN} ${INSTALL_SCRIPT} ${WRKSRC}/bin/rbenv-install \
		${DESTDIR}${PREFIX}/bin/rbenv-install
	${RUN} ${INSTALL_SCRIPT} ${WRKSRC}/bin/rbenv-uninstall \
		${DESTDIR}${PREFIX}/bin/rbenv-uninstall
	${RUN} ${INSTALL_SCRIPT} ${WRKSRC}/bin/ruby-build \
		${DESTDIR}${PREFIX}/bin/ruby-build
	${RUN} ${INSTALL_MAN} ${WRKSRC}/share/man/man1/ruby-build.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ruby-build.1
	${RUN} cd ${WRKSRC} && ${FIND} share/ruby-build -type f | \
		${XARGS} -I {} ${INSTALL_DATA} {} \
		${DESTDIR}${PREFIX}/share/ruby-build

.include "../../mk/bsd.pkg.mk"
