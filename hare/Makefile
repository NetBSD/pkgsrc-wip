# $NetBSD$

DISTNAME=	hare-0
CATEGORIES=	lang
GIT_REPO=	https://git.sr.ht/~sircmpwn/hare
GIT_BRANCH=	master
GIT_REVISION=	6390e11472e2393e4b26bf2e81c2d762546187b0

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://harelang.org/
COMMENT=	The Hare programming language
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

MAKE_FLAGS+=	BINDIR=${BINDIR}
MAKE_FLAGS+=	LIBDIR=${LIBDIR}
MAKE_FLAGS+=	MANDIR=${MANDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

TOOL_DEPENDS+=		harec-[0-9]*:../../wip/harec
TOOL_DEPENDS+=		qbe>=1.1:../../lang/qbe
TOOL_DEPENDS+=		scdoc-[0-9]*:../../textproc/scdoc

pre-configure:
	${RUN} ${CP} -f ${FILESDIR}/config.mk ${WRKSRC}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
