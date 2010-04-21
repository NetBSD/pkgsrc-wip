# $NetBSD: Makefile,v 1.1.1.1 2010/04/21 08:08:26 fhajny Exp $

DISTNAME=		passenger-2.2.11
PKGNAME=		${APACHE_PKG_PREFIX}-${DISTNAME}
CATEGORIES=		www

MASTER_SITES=		http://rubyforge.org/frs/download.php/69546/
MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.modrails.com/
COMMENT=		Apache module for easy and robust deployment of Rails applications
LICENSE=		mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		pax

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_APACHE_ACCEPTED=	apache2 apache22
APACHE_MODULE=		YES

BUILD_DEPENDS+=		rake>=0.8.1:../../devel/rake
DEPENDS+=		rubygems>=1.2.0:../../misc/rubygems
DEPENDS+=		${RUBY_PKGPREFIX}-rack-[0-9]*:../../www/ruby-rack

REPLACE_INTERPRETER+=	ruby
REPLACE.ruby.old=	.*ruby[0-9.]*
REPLACE.ruby.new=	${RUBY}
REPLACE_FILES.ruby=	bin/passenger-config
REPLACE_FILES.ruby+=	bin/passenger-install-apache2-module
REPLACE_FILES.ruby+=	bin/passenger-install-nginx-module
REPLACE_FILES.ruby+=	bin/passenger-make-enterprisey
REPLACE_FILES.ruby+=	bin/passenger-memory-stats
REPLACE_FILES.ruby+=	bin/passenger-spawn-server
REPLACE_FILES.ruby+=	bin/passenger-status
REPLACE_FILES.ruby+=	bin/passenger-stress-test

SUBST_CLASSES+=		rake
SUBST_STAGE.rake=	post-patch
SUBST_MESSAGE.rake=	Fixing installation directories
SUBST_FILES.rake=	Rakefile ext/common/Utils.cpp
SUBST_SED.rake=		-e 's,@PREFIX@,${PREFIX},'
SUBST_SED.rake+=	-e 's,@RUBY_VENDORLIB@,${RUBY_VENDORLIB},'
SUBST_SED.rake+=	-e 's,@RUBY_VENDORARCHLIB@,${RUBY_VENDORARCHLIB},'

do-build:
	cd ${WRKSRC} && ./bin/passenger-install-apache2-module -a

do-install:
	cd ${WRKSRC} && DESTDIR=${DESTDIR} PREFIX=${PREFIX} MANDIR=${PKGMANDIR} rake pkgsrc

.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
