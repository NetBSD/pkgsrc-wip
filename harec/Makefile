# $NetBSD$

DISTNAME=	harec-0
CATEGORIES=	lang
GIT_REPO=	https://git.sr.ht/~sircmpwn/harec
GIT_BRANCH=	master
GIT_REVISION=	fba0a9b547a3462d65a45ec93f78a07da58beabf

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

BUILD_DEPENDS+=		qbe-[0-9]*:../../wip/qbe

# XXX XXX XXX
# >> Creating .build/config.mk... rt not supported for NetBSD
do-configure:
	${RUN} cd ${WRKSRC} && ${CONFIG_SHELL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} ||:

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
