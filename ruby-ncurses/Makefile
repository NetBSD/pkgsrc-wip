# $NetBSD: Makefile,v 1.2 2004/04/08 14:23:27 rasputnik Exp $

DISTNAME=	${NAME}-ruby-${VER}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${NAME}-${VER}
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/ncurses-ruby/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://ncurses-ruby.berlios.de/
COMMENT=	Ruby interface to ncurses

BROKEN=	problem with latest ncurses - "Undefined symbol "_unctrl" (symnum = 284) - /usr/pkg/lib/ruby/1.6/i386-netbsdelf/ncurses.so (LoadError) "
DIST_SUBDIR=	ruby
NAME=	ncurses
VER=	0.8

DEPENDS+=	ncurses>=5.3:../../devel/ncurses

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
