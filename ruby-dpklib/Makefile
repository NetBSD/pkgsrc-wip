# $NetBSD: Makefile,v 1.2 2004/12/16 22:19:43 thomasklausner Exp $

DISTNAME= 	dpklib-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://devel.korinkan.co.jp/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://devel.korinkan.co.jp/dpklib/
COMMENT=	Ruby utility library

USE_RUBY_SETUP=	yes
VER=  		1.0.6
RUBY_SETUP=	install.rb

REPLACE_RUBY+=	bin/dpkruby-array bin/dpkruby-discoveryd bin/dpkruby-exec \
		bin/dpkruby-filter-replace bin/dpkruby-findres \
		bin/dpkruby-getopts bin/dpkruby-install bin/dpkruby-mvgsub \
		bin/dpkruby-passwd bin/dpkruby-rbconfig bin/dpkruby-release \
		bin/dpkruby-rubyc-symbols bin/dpkruby-runit \
		bin/dpkruby-rwpath sample/recreate-table.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/dpklib
	${INSTALL_DATA} ${WRKSRC}/sample/recreate-table.rb \
		${RUBY_EXAMPLESDIR}/dpklib

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
