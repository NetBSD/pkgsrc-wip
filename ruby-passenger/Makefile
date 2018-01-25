# $NetBSD$

PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}

COMMENT=		Modules for running Ruby on Rails and Rack applications

RUBY_VERSIONS_ACCEPTED=	22 23	# www/ruby-rack

.include "Makefile.common"

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
DEPENDS+=		${RUBY_PKGPREFIX}-daemon_controller>=1.2.0:../../devel/ruby-daemon_controller
DEPENDS+=		${RUBY_PKGPREFIX}-rack-[0-9]*:../../www/ruby-rack

INSTALL_ENV+=		FS_PREFIX=${PREFIX}
INSTALL_ENV+=		FS_DOCDIR=${PREFIX}/share/doc
INSTALL_ENV+=		RUBYLIBDIR=${PREFIX}/${RUBY_VENDORLIB_BASE}
INSTALL_ENV+=		RUBYARCHDIR=${PREFIX}/${RUBY_ARCHLIB}
INSTALL_ENV+=		APACHE2_MODULE_PATH=${PREFIX}/lib/httpd/mod_passenger.so
INSTALL_ENV+=		NATIVE_PACKAGING_METHOD=pkgsrc

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man8

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${RAKE} agent nginx nginx:as_dynamic_module native_support

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${RAKE} fakeroot
	${INSTALL_MAN} ${WRKSRC}/man/passenger-config.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/passenger-memory-stats.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-status.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
