# $NetBSD$

DISTNAME=	jj-fzf-0.25.0
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
USE_TOOLS+=	gmake bash:run
MAKE_FLAGS+=	SHELL=${BASH}

REPLACE_BASH+=	jj-fzf

INSTALLATION_DIRS+=	bin share/doc/jj-fzf

# https://github.com/tim-janik/jj-fzf/issues/7
do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jj-fzf ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/jj-fzf

.include "../../mk/bsd.pkg.mk"
