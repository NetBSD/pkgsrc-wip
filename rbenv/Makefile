# $NetBSD$

DISTNAME=	rbenv-1.3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rbenv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://rbenv.org/
COMMENT=	Ruby version manager
LICENSE=	mit

NO_BUILD=	yes

USE_TOOLS=	bash
USE_LANGUAGES=	# none

DEPENDS+=	ruby-build-[0-9]*:../../local/ruby-build

REPLACE_BASH=	libexec/rbenv* rbenv.d/exec/gem-rehash.bash

INSTALLATION_DIRS=	bin libexec/rbenv/hooks/exec/gem-rehash
INSTALLATION_DIRS+=	share/bash-completion/completions ${PKGMANDIR}/man1

OWN_DIRS+=	${PKG_SYSCONFDIR}/rbenv.d/exec
OWN_DIRS+=	${PKG_SYSCONFDIR}/rbenv.d/exec/gem-rehash
REQD_FILES+=	${PREFIX}/libexec/rbenv/hooks/exec/gem-rehash.bash \
		${PKG_SYSCONFDIR}/rbenv.d/exec/gem-rehash.bash
REQD_FILES+=	${PREFIX}/libexec/rbenv/hooks/exec/gem-rehash/rubygems_plugin.rb \
		${PKG_SYSCONFDIR}/rbenv.d/exec/gem-rehash/rubygems_plugin.rb

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	libexec/rbenv
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	PKG_SYSCONFDIR PREFIX

do-install:
	${RUN} ${INSTALL_DATA} ${WRKSRC}/rbenv.d/exec/gem-rehash.bash \
		${DESTDIR}${PREFIX}/libexec/rbenv/hooks/exec/gem-rehash.bash
	${RUN} ${INSTALL_DATA} ${WRKSRC}/rbenv.d/exec/gem-rehash/rubygems_plugin.rb \
		${DESTDIR}${PREFIX}/libexec/rbenv/hooks/exec/gem-rehash/rubygems_plugin.rb
	${RUN} ${INSTALL_DATA} ${WRKSRC}/completions/rbenv.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/rbenv
	${RUN} ${INSTALL_MAN} ${WRKSRC}/share/man/man1/rbenv.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rbenv.1
	${RUN} cd ${WRKSRC} && cd libexec && ${FIND} . -type f ! -name "*.orig" | \
		${XARGS} -I {} ${INSTALL_SCRIPT} {} \
		${DESTDIR}${PREFIX}/libexec/rbenv/{}
	${RUN} ${LN} -sf ${DESTDIR}${PREFIX}/libexec/rbenv/rbenv \
		${DESTDIR}${PREFIX}/bin/rbenv

.include "../../mk/bsd.pkg.mk"
