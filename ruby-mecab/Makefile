# $NetBSD: Makefile,v 1.11 2007/05/09 13:21:10 obache Exp $

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-ruby-${MECAB_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES+=	ruby

COMMENT=	MeCab ruby module

USE_LANGUAGES=	c c++
REPLACE_RUBY+=		test.rb
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes

do-test:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC};							\
	env ${TEST_ENV} ${RUBY} test.rb

.include "../../wip/mecab/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
