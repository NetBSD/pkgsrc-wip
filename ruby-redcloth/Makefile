# $NetBSD: Makefile,v 1.3 2004/04/03 21:26:51 rasputnik Exp $

DISTNAME=	redcloth-${VER}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=   http://rubyforge.org/download.php/472/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.whytheluckystiff.net/ruby/redcloth/
COMMENT=		Textile library for Ruby

VER=	2.0.3
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/redcloth
	${INSTALL_DATA} ${WRKSRC}/doc/README ${RUBY_DOCDIR}/redcloth

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
