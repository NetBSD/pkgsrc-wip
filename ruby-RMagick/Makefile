# $NetBSD: Makefile,v 1.9 2008/06/20 04:35:02 obache Exp $

DISTNAME=	RMagick-2.5.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/38050/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby binding to ImageMagick

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

CONFIGURE_ARGS+=	--doc-dir=${DESTDIR}${RUBY_DOCDIR}/RMagick
CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE}
CONFIGURE_ARGS+=	--siterubyver=${PREFIX}/${RUBY_VENDORLIB}
CONFIGURE_ARGS+=	--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}
USE_TOOLS+=		gs pax

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/RMagick
	cd ${WRKSRC}/examples && \
		pax -rw -pp -pm . ${DESTDIR}${RUBY_EXAMPLESDIR}/RMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
