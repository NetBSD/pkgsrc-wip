# $NetBSD: Makefile,v 1.7 2006/10/29 08:32:45 shattered Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-java-${MECAB_VERSION}
PKGNAME=	java-mecab-${MECAB_VERSION}
CATEGORIES=	japanese textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mecab/21192/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://mecab.sourceforge.jp/
COMMENT=	MeCab java module

USE_LANGUAGES=	c++

TEST_TARGET=	test

do-install:
	${INSTALL_LIB} ${WRKSRC:Q}/libMeCab.so ${PREFIX:Q}/lib
	${INSTALL_LIB} ${WRKSRC:Q}/MeCab.jar ${PREFIX:Q}/lib

.include "../../wip/mecab/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
