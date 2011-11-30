# $NetBSD: Makefile,v 1.6 2011/11/30 11:10:31 fhajny Exp $

DISTNAME=		passenger-3.0.11
PKGNAME=		${APACHE_PKG_PREFIX}-${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		www

MASTER_SITES=		http://rubyforge.org/frs/download.php/75548/
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

CONFLICTS+=		ap2[0-9]*-ruby[1-9][0-9]-passenger-*

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
REPLACE_FILES.ruby+=	helper-scripts/passenger-spawn-server
REPLACE_FILES.ruby+=	helper-scripts/prespawn

CHECK_INTERPRETER_SKIP+=	share/phusion-passenger/source/*
CHECK_INTERPRETER_SKIP+=	${RUBY_VENDORLIB}/phusion_passenger/wsgi/request_handler.py

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

.include "../../mk/compiler.mk"

# GCC 4.6 enforces C99 compliance on C++ code, which implies _XOPEN_SOURCE=600
# or later on SunOS, and fails if earlier set is requested

.if ${OPSYS} == "SunOS" && !empty(CC_VERSION:Mgcc-4.6.*)
SUBST_CLASSES+=		xopen
SUBST_MESSAGE.xopen=	Fixing _XOPEN_SOURCE for GCC 4.6
SUBST_STAGE.xopen=	post-patch
SUBST_FILES.xopen=	lib/phusion_passenger/platform_info/compiler.rb
SUBST_SED.xopen=	-e 's,-D_XOPEN_SOURCE=500 -D_XPG4_2,,'
.endif

post-patch:
	rm ${WRKSRC}/lib/phusion_passenger/admin_tools/memory_stats.rb.orig

do-build:
	cd ${WRKSRC} && ./bin/passenger-install-apache2-module -a

do-install:
	cd ${WRKSRC} && DESTDIR=${DESTDIR} PREFIX=${PREFIX} MANDIR=${PKGMANDIR} rake${RUBY_VER} pkgsrc
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-config.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/passenger-stress-test.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/passenger-make-enterprisey.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-memory-stats.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-status.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../www/curl/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
