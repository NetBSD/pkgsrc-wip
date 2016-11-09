# $NetBSD: Makefile,v 1.1 2015/04/25 21:55:59 ahp-nils Exp $

DISTNAME=	rdiscount-2.2.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	http://dafoster.net/projects/rdiscount/
COMMENT=	Converts documents in Markdown syntax to HTML
LICENSE=	modified-bsd

INSTALLATION_DIRS+=		${PKGMANDIR}/man1/

post-install:
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/rdiscount.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rdiscount.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
