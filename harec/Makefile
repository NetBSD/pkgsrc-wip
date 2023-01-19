# $NetBSD$

DISTNAME=	harec-0
CATEGORIES=	lang
GIT_REPO=	https://git.sr.ht/~sircmpwn/harec
GIT_BRANCH=	master
GIT_REVISION=	cfcc22785c94716c0e96be23081d8bfd1f6c0466

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://harelang.org/
COMMENT=	Hare language bootstrap compiler
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--bindir=${BINDIR}
CONFIGURE_ARGS+=	--libdir=${LIBDIR}
CONFIGURE_ARGS+=	--mandir=${MANDIR}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sharedir=${SHAREDIR}

# Requires QBE with support for 'blit' instruction, which is past 1.0
BUILD_DEPENDS+=		qbe-git-[0-9]*:../../wip/qbe-git

do-configure:
	${RUN} cd ${WRKSRC} && ${CONFIG_SHELL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
