# $NetBSD: Makefile,v 1.1.1.1 2004/02/10 11:28:09 rasputnik Exp $

DISTNAME= dpklib-${VER}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=	http://devel.korinkan.co.jp/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://devel.korinkan.co.jp/dpklib/
COMMENT=	Ruby utility library

DIST_SUBDIR=	ruby
VER=  1.0.6

USE_RUBY=   yes
USE_RUBY_SETUP=   yes
RUBY_SETUP=   install.rb

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
