# $NetBSD: Makefile,v 1.7 2014/10/29 12:59:17 fhajny Exp $

PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}

COMMENT=		Modules for running Ruby on Rails and Rack applications

.include "Makefile.common"

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
DEPENDS+=		${RUBY_PKGPREFIX}-daemon_controller>=1.2.0:../../devel/ruby-daemon_controller
DEPENDS+=		${RUBY_PKGPREFIX}-rack-[0-9]*:../../www/ruby-rack
.if ${RUBY_VERSION_DEFAULT} == 18
DEPENDS+=		${RUBY_PKGPREFIX}-rubygems>=1.2.0:../../misc/rubygems
.endif

RUBY_VERSIONS_ACCEPTED=	22 23	# www/ruby-rack

INSTALL_ENV+=		FS_PREFIX=${PREFIX}
INSTALL_ENV+=		FS_DOCDIR=${PREFIX}/share/doc
INSTALL_ENV+=		RUBYLIBDIR=${PREFIX}/${RUBY_VENDORLIB_BASE}
INSTALL_ENV+=		RUBYARCHDIR=${PREFIX}/${RUBY_ARCHLIB}
INSTALL_ENV+=		APACHE2_MODULE_PATH=${PREFIX}/lib/httpd

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${RAKE} common:clean agents

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${RAKE} fakeroot
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-config.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/passenger-memory-stats.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-status.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
