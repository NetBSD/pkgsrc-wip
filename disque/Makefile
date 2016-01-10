# $NetBSD$

PKGNAME=	disque-1.0rc1
DISTNAME=	disque-1.0-rc1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=antirez/}
GITHUB_PROJECT=	disque
GITHUB_TAG=	1.0-rc1

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/antirez/disque
COMMENT=	Distributed message broker
LICENSE=	modified-bsd

USE_LANGUAGES=	c99
USE_TOOLS+=	gmake

SUBST_CLASSES+=			destdir-support
SUBST_STAGE.destdir-support=	pre-install
SUBST_MESSAGE.destdir-support=	Adding DESTDIR support.
SUBST_FILES.destdir-support=	src/Makefile
SUBST_SED.destdir-support=	-e 's,$$(PREFIX),$$(DESTDIR)$$(PREFIX),'

.include "../../mk/subst.mk"
.include "../../mk/bsd.pkg.mk"
