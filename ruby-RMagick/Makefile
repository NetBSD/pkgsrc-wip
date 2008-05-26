# $NetBSD: Makefile,v 1.6 2008/05/26 13:59:46 tnn2 Exp $

DISTNAME=	RMagick-2.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/34654/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby binding to ImageMagick

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

CONFIGURE_ARGS+=	--doc-dir=${DESTDIR}${RUBY_DOCDIR}/RMagick
USE_TOOLS+=		gs pax

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/RMagick
	cd ${WRKSRC}/examples && \
		pax -rw -pp -pm . ${DESTDIR}${RUBY_EXAMPLESDIR}/RMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
