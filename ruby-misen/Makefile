# $NetBSD: Makefile,v 1.1.1.1 2004/02/10 11:31:15 rasputnik Exp $

DISTNAME= misen-${VER}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	www textproc
MASTER_SITES=	http://devel.korinkan.co.jp/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://devel.korinkan.co.jp/misen/
COMMENT=	Ruby text template library

DIST_SUBDIR=	ruby
VER=  0.11.1

DEPENDS+=	${RUBY_PKGNAMEPREFIX}dpklib>=1.0.6:../../wip/${RUBY_PKGNAMEPREFIX}dpklib
USE_RUBY=   yes
USE_RUBY_SETUP=   yes
RUBY_SETUP=   install.rb

#do-install:
#	cd ${WRKSRC} && ${RUBY} install.rb
#	${CP} -R ${WRKSRC}/sample ${RUBY_EXAMPLESDIR}/amrita

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
