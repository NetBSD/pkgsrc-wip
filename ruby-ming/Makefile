# $NetBSD: Makefile,v 1.2 2004/01/03 22:27:18 mpasternak Exp $

DISTNAME=	ming-ruby-${VER}
PKGNAME=	ruby-ming-${VER}
CATEGORIES=	graphics
MASTER_SITES=	http://madscientist.jp/~ikegami/sources/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://madscientist.jp/~ikegami/ruby/ming/
COMMENT=	Ruby extension to drive the Ming SWF library

USE_BUILDLINK2=	# defined

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

.include "../../wip/ming/buildlink2.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
