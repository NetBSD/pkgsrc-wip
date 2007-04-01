# $NetBSD: Makefile,v 1.9 2007/04/01 02:19:12 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-java-${MECAB_VERSION}
PKGNAME=	java-mecab-${MECAB_VERSION}
CATEGORIES=	japanese textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mecab/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mecab.sourceforge.net/
COMMENT=	MeCab java module

USE_LANGUAGES=	c++

TEST_TARGET=	test

do-install:
	${INSTALL_LIB} ${WRKSRC:Q}/libMeCab.so ${PREFIX:Q}/lib
	${INSTALL_LIB} ${WRKSRC:Q}/MeCab.jar ${PREFIX:Q}/lib

.include "../../wip/mecab/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
