# $NetBSD$

DISTNAME=	jj-fzf-0.38.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tim-janik/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tim-janik/jj-fzf/
COMMENT=	Text UI for Jujutsu based on fzf
LICENSE=	mpl-2.0

#TOOL_DEPENDS+=	shellcheck-[0-9]*:../../shells/shellcheck
DEPENDS+=	jj-[0-9]*:../../devel/jj
DEPENDS+=	fzf-[0-9]*:../../sysutils/fzf

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake bash:run gsed:run
MAKE_FLAGS+=	SHELL=${BASH}

REPLACE_BASH+=	jj-fzf
REPLACE_BASH+=	*.sh
REPLACE_BASH+=	*/*.sh

SUBST_CLASSES+=		python
SUBST_SED.python+=	-e s",python3,${PYTHONBIN},"
SUBST_FILES.python+=	preflight.sh
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Fixing path to Python interpreter.

SUBST_CLASSES+=		mktemp
SUBST_SED.mktemp+=	-e "s,mktemp --tmpdir,mktemp -t /tmp,"
SUBST_FILES.mktemp+=	contrib/jj-am.sh
SUBST_FILES.mktemp+=	lib/setup.sh
SUBST_FILES.mktemp+=	screencasts/prepare.sh
SUBST_FILES.mktemp+=	tests/utils.sh
SUBST_STAGE.mktemp=	pre-build
SUBST_MESSAGE.mktemp=	Using more portable mktemp flags.

REPLACE_PYTHON+=	lib/gen-message.py

INSTALLATION_DIRS+=	bin libexec/lib share/doc/jj-fzf

# https://github.com/tim-janik/jj-fzf/issues/7
do-build:
	echo '#!/bin/sh' > ${WRKDIR}/jj-fzf
	echo '${PREFIX}/libexec/jj-fzf "$$@"' > ${WRKDIR}/jj-fzf

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jj-fzf ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jj-fzf ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/*.sh ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/lib/*.sh ${DESTDIR}${PREFIX}/libexec/lib
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/jj-fzf

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
