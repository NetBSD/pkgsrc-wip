# $NetBSD: Makefile,v 1.4 2008/08/07 09:18:15 obache Exp $

DISTNAME=	ruby-gettext-package-1.92.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/ruby-(.*)-package/\1/}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/40668/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://gettext.rubyforge.org/
COMMENT=	Ruby L10n library like as GNU GetText

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_SETUP=		yes
RUBY_HAS_ARCHLIB=	yes
REPLACE_RUBY=		bin/rgettext bin/rmsgfmt bin/rmsgmerge

CONFIGURE_ARGS+=	--siterubyver=${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
