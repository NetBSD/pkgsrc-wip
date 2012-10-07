# $NetBSD: Makefile,v 1.3 2012/10/07 17:17:45 asau Exp $
#

DISTNAME=		tpp-1.3.1
CATEGORIES=		graphics
MASTER_SITES=		http://synflood.at/tpp/

MAINTAINER=		esg@sdf.lonestar.org
HOMEPAGE=		http://synflood.at/tpp/
COMMENT=		Tpp is an ncurses-based presentation tool

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-ncurses>=0.8:../../devel/ruby-ncurses
DEPENDS+=	figlet-[0-9]*:../../misc/figlet

NO_BUILD=	yes

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	MANPATH=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
