# $NetBSD: Makefile,v 1.1.1.1 2003/10/05 19:05:55 adrian_p Exp $

.include "Makefile.common"

COMMENT=	Open relay scanner

USE_BUILDLINK2=	YES
ALL_TARGET=	freebsd

PTHREAD_OPTS=	require

CONF_FILES=     ${PREFIX}/share/examples/smtprc/auto.conf \
			${PKG_SYSCONFDIR}/auto.conf
CONF_FILES+=    ${PREFIX}/share/examples/smtprc/email.tmpl \
			${PKG_SYSCONFDIR}/email.tmpl
CONF_FILES+=	${PREFIX}/share/examples/smtprc/rcheck.conf \
			${PKG_SYSCONFDIR}/rcheck.conf

pre-build:
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' \
		< ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.new
	@${CP} ${WRKSRC}/Makefile.new ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smtprc
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/smtprc
	${INSTALL_PROGRAM} ${WRKSRC}/smtprc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/auto.conf ${PREFIX}/share/examples/smtprc
	${INSTALL_DATA} ${WRKSRC}/email.tmpl ${PREFIX}/share/examples/smtprc 
	${INSTALL_DATA} ${WRKSRC}/rcheck.conf ${PREFIX}/share/examples/smtprc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/smtprc
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/smtprc
	${INSTALL_MAN} ${WRKSRC}/smtprc.1 ${PREFIX}/man/man1

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
