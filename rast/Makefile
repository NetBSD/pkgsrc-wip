# $NetBSD: Makefile,v 1.1.1.1 2011/02/21 11:36:58 obache Exp $
#

DISTNAME=	rast-0.3.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://projects.netlab.jp/rast/archives/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://projects.netlab.jp/rast/
COMMENT=	Full-text search system
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-bz2-[0-9]*:../../archives/ruby-bz2
DEPENDS+=	${RUBY_PKGPREFIX}-zip-[0-9]*:../../archives/ruby-zip
DEPENDS+=	${RUBY_PKGPREFIX}-mp3info-[0-9]*:../../audio/ruby-mp3info
DEPENDS+=	${RUBY_PKGPREFIX}-tmail-[0-9]*:../../mail/ruby-tmail
DEPENDS+=	${RUBY_PKGPREFIX}-htree-[0-9]*:../../textproc/ruby-htree

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-ruby=${RUBY}
CONFIGURE_ARGS+=	--with-rubylibdir=${BUILDLINK_PREFIX.${RUBY_BASE}}/${RUBY_VENDORLIB}
CONFIGURE_ARGS+=	--with-rubyarchdir=${BUILDLINK_PREFIX.${RUBY_BASE}}/${RUBY_VENDORARCHLIB}

MAKE_JOBS_SAFE=		no

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/mecab/buildlink3.mk"
.include "../../textproc/xmlrpc-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
