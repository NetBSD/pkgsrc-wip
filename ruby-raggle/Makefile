# $NetBSD: Makefile,v 1.1.1.1 2004/02/11 17:17:23 rasputnik Exp $

DISTNAME= raggle-${VER}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	www textproc
MASTER_SITES=	http://www.raggle.org/files/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.raggle.org/
COMMENT=	Console-based screen(1)-aware RSS reader written in Ruby

DIST_SUBDIR=	ruby
VER=  0.2.4

DEPENDS+=	ruby-rexml>=2.4.0:../../textproc/ruby-rexml
DEPENDS+=	ruby-syck>=0.42:../../wip/ruby-syck
DEPENDS+=	ruby-ncurses>=0.8:../../wip/ruby-ncurses

NO_BUILD=	yes
USE_RUBY=   yes

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
