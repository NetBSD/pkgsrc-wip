# $NetBSD: Makefile,v 1.13 2008/05/26 13:59:46 tnn2 Exp $

DISTNAME=	ming-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ming-${VER}
CATEGORIES=	multimedia
MASTER_SITES=	http://rubyforge.org/frs/download.php/30011/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mingruby.rubyforge.org/
COMMENT=	Ruby extension to drive the Ming SWF library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pax
USE_RUBY_SETUP=		yes
VER=			0.1.9

REPLACE_RUBY_DIRS=	${WRKSRC}/examples

post-install:
		${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/ming
		cd ${WRKSRC}/examples && \
			pax -wrppm '-s|.*/CVS.*$$||' . ${DESTDIR}${RUBY_EXAMPLESDIR}/ming

.include "../../wip/ming/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
