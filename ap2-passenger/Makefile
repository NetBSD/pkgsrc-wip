# $NetBSD: Makefile,v 1.4 2010/11/30 11:53:29 fhajny Exp $

DISTNAME=		passenger-3.0.0
PKGNAME=		${APACHE_PKG_PREFIX}-${DISTNAME}
CATEGORIES=		www

MASTER_SITES=		http://rubyforge.org/frs/download.php/72923/
MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.modrails.com/
COMMENT=		Apache module for easy and robust deployment of Rails applications
LICENSE=		mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		pax:build

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_APACHE_ACCEPTED=	apache2 apache22
APACHE_MODULE=		YES

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
DEPENDS+=		${RUBY_PKGPREFIX}-rack-[0-9]*:../../www/ruby-rack

.if empty(RUBY_VERSION_DEFAULT) || ${RUBY_VERSION_DEFAULT} == 1.8
BUILD_DEPENDS+=		${RUBY_PKGPREFIX}-rake>=0.8.1:../../devel/rake
DEPENDS+=		${RUBY_PKGPREFIX}-rubygems>=1.2.0:../../misc/rubygems
.endif

PASSENGER_LOGDIR?=	${VARBASE}/log/passenger
PASSENGER_VARDIR?=	${VARBASE}/spool/passenger

REPLACE_INTERPRETER+=	ruby
REPLACE.ruby.old=	.*ruby[0-9.]*
REPLACE.ruby.new=	${RUBY}
REPLACE_FILES.ruby=	bin/passenger
REPLACE_FILES.ruby+=	bin/passenger-config
REPLACE_FILES.ruby+=	bin/passenger-install-apache2-module
REPLACE_FILES.ruby+=	bin/passenger-install-nginx-module
REPLACE_FILES.ruby+=	bin/passenger-make-enterprisey
REPLACE_FILES.ruby+=	bin/passenger-memory-stats
REPLACE_FILES.ruby+=	bin/passenger-status
REPLACE_FILES.ruby+=	bin/passenger-stress-test

CHECK_INTERPRETER_SKIP=	share/phusion-passenger/source/*

SUBST_CLASSES+=		rake
SUBST_STAGE.rake=	post-patch
SUBST_MESSAGE.rake=	Fixing installation directories
SUBST_FILES.rake=	build/packaging.rb ext/apache2/Configuration.hpp
SUBST_FILES.rake+=	ext/common/ResourceLocator.h ext/nginx/Configuration.c
SUBST_FILES.rake+=	lib/phusion_passenger/admin_tools/memory_stats.rb
SUBST_FILES.rake+=	lib/phusion_passenger.rb
SUBST_SED.rake=		-e 's,@PREFIX@,${PREFIX},'
SUBST_SED.rake+=	-e 's,@RUBY_VERSION@,${RUBY_VERSION},'
SUBST_SED.rake+=	-e 's,@RUBY_ARCH@,${RUBY_ARCH},'
SUBST_SED.rake+=	-e 's,@RUBY_VENDORLIB@,${RUBY_VENDORLIB},'
SUBST_SED.rake+=	-e 's,@RUBY_VENDORARCHLIB@,${RUBY_VENDORARCHLIB},'
SUBST_SED.rake+=	-e 's,@PASSENGER_VARDIR@,${PASSENGER_VARDIR},'
SUBST_SED.rake+=	-e 's,@PASSENGER_LOGDIR@,${PASSENGER_LOGDIR},'

CFLAGS+=		-I${PREFIX}/include/ruby-1.9

post-patch:
	rm ${WRKSRC}/lib/phusion_passenger/admin_tools/memory_stats.rb.orig

do-build:
	cd ${WRKSRC} && ./bin/passenger-install-apache2-module -a

do-install:
	cd ${WRKSRC} && DESTDIR=${DESTDIR} PREFIX=${PREFIX} MANDIR=${PKGMANDIR} rake${RUBY_VER} pkgsrc
	${INSTALL_MAN_DIR}	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN_DIR}	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-config.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/passenger-stress-test.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/passenger-make-enterprisey.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-memory-stats.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-status.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../www/curl/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
