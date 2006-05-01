# $NetBSD: Makefile,v 1.3 2006/05/01 12:06:29 obache Exp $

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-ruby-${MECAB_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mecab/20030/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://mecab.sourceforge.jp/
COMMENT=	MeCab ruby module

USE_LANGUAGES+=	c++
REPLACE_RUBY+=		test.rb
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes

do-test:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC};							\
	${SETENV} ${TEST_ENV} ${RUBY} test.rb

.include "../../wip/mecab/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
