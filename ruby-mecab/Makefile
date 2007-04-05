# $NetBSD: Makefile,v 1.10 2007/04/05 12:23:28 obache Exp $

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-ruby-${MECAB_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mecab/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mecab.sourceforge.net/
COMMENT=	MeCab ruby module

USE_LANGUAGES=	c c++
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
