# $NetBSD: Makefile,v 1.3 2006/05/01 12:06:29 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-java-${MECAB_VERSION}
PKGNAME=	java-mecab-${MECAB_VERSION}
CATEGORIES=	japanese textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mecab/20032/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://mecab.sourceforge.jp/
COMMENT=	MeCab java module

USE_LANGUAGES+=	c++

do-install:
	${BSD_INSTALL_LIB} ${WRKSRC:Q}/libMeCab.so ${PREFIX:Q}/lib
	${BSD_INSTALL_LIB} ${WRKSRC:Q}/MeCab.jar ${PREFIX:Q}/lib

.include "../../wip/mecab/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
