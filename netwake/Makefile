# $NetBSD$

DISTNAME=	netwake-0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/sjmulder/netwake
COMMENT=	Wake-on-LAN utility with lookup file support
LICENSE=	2-clause-bsd

USE_TOOLS=	gmake
BUILD_DIRS=	cli

SUBST_CLASSES=		confdir
SUBST_MESSAGE.confdir=	Fix /etc path in man page
SUBST_STAGE.confdir=	pre-configure
SUBST_FILES.confdir=	cli/netwake.1
SUBST_SED.confdir=	-e "s,/etc,${PKG_SYSCONFDIR},"

MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
