# $NetBSD: Makefile,v 1.4 2004/05/10 22:13:11 blef Exp $

DISTNAME=	ming-ruby-${VER}
PKGNAME=	ruby-ming-${VER}
CATEGORIES=	graphics
MASTER_SITES=	http://madscientist.jp/~ikegami/sources/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://madscientist.jp/~ikegami/ruby/ming/
COMMENT=	Ruby extension to drive the Ming SWF library

USE_BUILDLINK3=	yes

VER=		0.1.6
USE_RUBY_SETUP=	yes

EXAMPLES=	README action.rb button.rb drag.rb \
	gradient.rb gradientxform.rb keypress.rb mousetrack.rb \
	newbutton.rb shape.rb sparks.rb sprite.rb

post-install:
		${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/ming
.for f in ${EXAMPLES}
		${INSTALL_DATA} ${WRKSRC}/examples/$f ${RUBY_EXAMPLESDIR}/ming
.endfor

.include "../../wip/ming/buildlink3.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
