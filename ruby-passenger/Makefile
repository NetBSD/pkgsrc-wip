# $NetBSD: Makefile,v 1.4 2012/08/10 15:13:40 fhajny Exp $

PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}

COMMENT=		Modules for running Ruby on Rails and Rack applications

.include "Makefile.common"

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
DEPENDS+=		${RUBY_PKGPREFIX}-daemon_controller-[0-9]*:../../devel/ruby-daemon_controller
DEPENDS+=		${RUBY_PKGPREFIX}-rack-[0-9]*:../../www/ruby-rack
.if ${RUBY_VERSION_DEFAULT} == 18
DEPENDS+=		${RUBY_PKGPREFIX}-rubygems>=1.2.0:../../misc/rubygems
.endif

do-build:
	cd ${WRKSRC}/build && ${PKGSRC_SETENV} ${MAKE_ENV} ${RAKE} common:clean agents

do-install:
	cd ${WRKSRC} && DESTDIR=${DESTDIR} PREFIX=${PREFIX} MANDIR=${PKGMANDIR} ${RAKE} pkgsrc
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-config.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/passenger-memory-stats.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-status.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-stress-test.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
