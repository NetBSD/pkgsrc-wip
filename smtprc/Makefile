# $NetBSD: Makefile,v 1.7 2012/10/07 15:31:11 asau Exp $

.include "Makefile.common"

COMMENT=	Open relay scanner

BUILD_TARGET=	freebsd

PTHREAD_OPTS=	require

CONF_FILES=	${PREFIX}/share/examples/smtprc/auto.conf \
			${PKG_SYSCONFDIR}/auto.conf
CONF_FILES+=	${PREFIX}/share/examples/smtprc/email.tmpl \
			${PKG_SYSCONFDIR}/email.tmpl
CONF_FILES+=	${PREFIX}/share/examples/smtprc/rcheck.conf \
			${PKG_SYSCONFDIR}/rcheck.conf

pre-build:
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' \
		< ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.new
	@${CP} ${WRKSRC}/Makefile.new ${WRKSRC}/Makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/smtprc
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/smtprc
	${INSTALL_PROGRAM} ${WRKSRC}/smtprc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/auto.conf ${DESTDIR}${PREFIX}/share/examples/smtprc
	${INSTALL_DATA} ${WRKSRC}/email.tmpl ${DESTDIR}${PREFIX}/share/examples/smtprc
	${INSTALL_DATA} ${WRKSRC}/rcheck.conf ${DESTDIR}${PREFIX}/share/examples/smtprc
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/smtprc
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/smtprc
	${INSTALL_MAN} ${WRKSRC}/smtprc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
