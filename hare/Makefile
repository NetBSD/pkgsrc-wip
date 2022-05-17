# $NetBSD$

DISTNAME=	hare-0
CATEGORIES=	lang
GIT_REPO=	https://git.sr.ht/~sircmpwn/hare
GIT_BRANCH=	master
GIT_REVISION=	d9870303ec34c851b5d5a06402d8009dac76d174

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

BUILD_DEPENDS+=		harec-[0-9]*:../../wip/harec
BUILD_DEPENDS+=		qbe-[0-9]*:../../wip/qbe
BUILD_DEPENDS+=		scdoc-[0-9]*:../../textproc/scdoc

pre-configure:
	${RUN} cd ${WRKSRC} && ${CP} -f config.example.mk config.mk

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
