# $NetBSD: Makefile,v 1.3 2004/12/16 22:19:44 thomasklausner Exp $

DISTNAME=	ncurses-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ncurses-${VER}
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/ncurses-ruby/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://ncurses-ruby.berlios.de/
COMMENT=	Ruby interface to ncurses

USE_RUBY_EXTCONF=	yes
VER=			0.8

EXAMPLES=		example.rb hello_ncurses.rb rain.rb read_line.rb \
			tclock.rb test_scanw.rb
.for f in ${EXAMPLES}
REPLACE_RUBY+=		sample/$f
.endfor

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/ncurses
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/$f ${RUBY_EXAMPLESDIR}/ncurses
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
