# $NetBSD: Makefile,v 1.2 2004/12/16 22:19:44 thomasklausner Exp $

DISTNAME= 	misen-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www textproc
MASTER_SITES=	http://devel.korinkan.co.jp/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://devel.korinkan.co.jp/misen/
COMMENT=	Ruby text template library

DEPENDS+=	${RUBY_PKGPREFIX}-dpklib>=1.0.6:../../wip/ruby-dpklib

USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
VER=		0.11.1

EXAMPLES=		acq-expand.rb bookmark.rb conditional.rb \
			hello-latex.rb hello-latex.sh hello.rb hello.sh
REPLACE_RUBY+=		bin/misen-expand
.for f in ${EXAMPLES}
REPLACE_RUBY+=		sample/$f
.endfor

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/misen
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/$f ${RUBY_EXAMPLESDIR}/misen
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
