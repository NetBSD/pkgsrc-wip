# $NetBSD: Makefile,v 1.1.1.1 2011/10/19 09:19:28 makoto Exp $

DISTNAME=	mop-1.9
CATEGORIES=     graphics
MASTER_SITES=   http://www.gentei.org/~yuuji/software/mop/
MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       http://www.gentei.org/~yuuji/software/mop/index-e.html
COMMENT=        Presentation with Web Browser written in ruby
LICENSE=	generic-nonlicense

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/ruby/rubyversion.mk"

INSTALLATION_DIRS=	share/${PKGBASE}
INSTALLATION_DIRS=	bin
USE_TOOLS=	pax

REPLACE_RUBY=   mop.rb
.include "../../lang/ruby/replace.mk"

do-install:
	(cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' .  ${DESTDIR}${PREFIX}/share/${PKGBASE})
	(cd ${DESTDIR}${PREFIX}; ln share/${PKGBASE}/mop.rb bin/${PKGBASE})

.include "../../mk/bsd.pkg.mk"
