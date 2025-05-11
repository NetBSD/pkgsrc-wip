# $NetBSD$

DISTNAME=	nvimpager-0.13.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=lucc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lucc/nvimpager/
COMMENT=	Use nvim as a pager
LICENSE=	2-clause-bsd

MAKE_FILE=	makefile
USE_TOOLS+=	bash:run

TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

REPLACE_BASH+=	nvimpager

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Adjusting paths and version for pkgsrc
SUBST_FILES.makefile=	makefile
SUBST_SED.makefile+=	-e '/^VERSION/s/.*/VERSION = ${PKGVERSION_NOREV}/'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},'

USE_LANGUAGES=	# none

do-build:
	# nothing

.include "../../mk/bsd.pkg.mk"
