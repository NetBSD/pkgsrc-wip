# $NetBSD: Makefile,v 1.1.1.1 2004/02/13 15:03:03 rasputnik Exp $

DISTNAME=	redcloth-${VER}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=yaml4r/}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.whytheluckystiff.net/ruby/redcloth/
COMMENT=		Textile library for Ruby

VER=	2.0.1
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/redcloth
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/redcloth

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
