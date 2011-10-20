# $NetBSD: Makefile,v 1.2 2011/10/20 12:34:01 makoto Exp $

DISTNAME=	mop-1.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.gentei.org/~yuuji/software/mop/
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gentei.org/~yuuji/software/mop/index-e.html
COMMENT=	Convert Draft HTML/CSS to suitable for Presentation with Web Browser
LICENSE=	generic-nonlicense

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/ruby/rubyversion.mk"

INSTALLATION_DIRS=	share/${PKGBASE}
INSTALLATION_DIRS=	bin
USE_TOOLS+=	pax

REPLACE_RUBY=	mop.rb
.include "../../lang/ruby/replace.mk"

do-install:
	(cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' .  ${DESTDIR}${PREFIX}/share/${PKGBASE})
	(set -e ; cd ${DESTDIR}${PREFIX}; ln share/${PKGBASE}/mop.rb bin/${PKGBASE})

.include "../../mk/bsd.pkg.mk"
