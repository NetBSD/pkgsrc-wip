# $NetBSD: Makefile,v 1.1.1.1 2004/02/11 15:48:37 rasputnik Exp $

DISTNAME=	${NAME}-ruby-${VER}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${NAME}-${VER}
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/ncurses-ruby/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://ncurses-ruby.berlios.de/
COMMENT=	Ruby interface to ncurses

DIST_SUBDIR=	ruby
NAME=	ncurses
VER=	0.8

DEPENDS+=	ncurses>=5.3:../../devel/ncurses

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
