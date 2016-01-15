# $NetBSD$

DISTNAME=	id3-0.80
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=squell/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squell.github.io/id3/
COMMENT=	ID3 mass tagger
LICENSE=	2-clause-bsd

MAKE_FILE=	makefile
MAKE_FLAGS+=	\
	prefix=${PREFIX} \
	mandir=${PREFIX}/${PKGMANDIR}

USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
