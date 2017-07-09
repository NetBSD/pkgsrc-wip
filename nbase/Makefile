# $NetBSD$
#

DISTNAME=	nbase-7.0.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheusov/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/nbase
COMMENT=	NetBSD userlevel portable to other UNIX-like systems
LICENSE=	modified-bsd

GITHUB_PROJECT=	nbase
DEPENDS+=	mk-configure>=0.29.1:../../devel/mk-configure

# BUILD_TARGET=		all-fgen
# INSTALL_TARGET=		install-fgen
# CONFIGURE_TARGET=	errorcheck-fgen

USE_LANGUAGES=		c
USE_TOOLS+=		yacc lex

TEST_TARGET=		test

.include "../../devel/mk-configure/mk-c.mk"

MAKE_FLAGS+=	PREFIX=${PREFIX}/nbase \
		MANDIR=${PREFIX}/nbase/${PKGMANDIR} \
		LINKSPREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
