# $NetBSD: Makefile,v 1.1.1.1 2004/01/28 16:41:26 rasputnik Exp $

DISTNAME=	amrita-${VER}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.brain-tokyo.jp/research/amrita/
COMMENT=	Ruby HTML Template library

DIST_SUBDIR=	ruby
VER=  1.0.2

CONFIGURE=	no
NO_BUILD=	yes
USE_RUBY=   yes

do-install:
	cd ${WRKSRC} && ${RUBY} install.rb
	${CP} -R ${WRKSRC}/sample ${RUBY_EXAMPLESDIR}/amrita

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
