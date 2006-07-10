# $NetBSD: Makefile,v 1.4 2006/07/10 05:30:48 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-java-${MECAB_VERSION}
PKGNAME=	java-mecab-${MECAB_VERSION}
CATEGORIES=	japanese textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mecab/20901/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://mecab.sourceforge.jp/
COMMENT=	MeCab java module

USE_LANGUAGES+=	c++

do-install:
	${INSTALL_LIB} ${WRKSRC:Q}/libMeCab.so ${PREFIX:Q}/lib
	${INSTALL_LIB} ${WRKSRC:Q}/MeCab.jar ${PREFIX:Q}/lib

.include "../../wip/mecab/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
