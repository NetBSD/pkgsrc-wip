# $NetBSD: Makefile,v 1.2 2004/03/29 00:22:39 minskim Exp $

DISTNAME=	syslog-ng-1.6.0rc4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/syslog-ng/1.6/src/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.balabit.com/products/syslog_ng/
COMMENT=	Syslog-ng tries to fill the gaps original syslogd's were lacking

GNU_CONFIGURE=	YES
#CONFIGURE_ARGS+=	--enable-tcp-wrapper
USE_BUILDLINK3=	YES

pre-build:
	@${CP} ${WRKSRC}/doc/syslog-ng.8 ${WRKSRC}/doc/syslog-ng.8.pre
	@${CP} ${WRKSRC}/doc/syslog-ng.conf.5 ${WRKSRC}/doc/syslog-ng.conf.5.pre

	@${SED} -e 's#@PREFIX@#${PREFIX}#g' \
	< ${WRKSRC}/doc/syslog-ng.8.pre > ${WRKSRC}/doc/syslog-ng.8

	@${SED} -e 's#@PREFIX@#${PREFIX}#g' \
	< ${WRKSRC}/doc/syslog-ng.conf.5.pre > ${WRKSRC}/doc/syslog-ng.conf.5

	cd ${WRKSRC}/doc/sgml && \
		${PAX} -O -zrf ${WRKSRC}/doc/sgml/syslog-ng.html.tar.gz

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/syslog-ng
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/syslog-ng
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/syslog-ng

	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/doc/syslog-ng.conf.demo \
		${PREFIX}/share/examples/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/doc/syslog-ng.conf.sample \
		${PREFIX}/share/examples/syslog-ng
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/syslog2ng ${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/doc/sgml/syslog-ng.html/*.html \
		${PREFIX}/share/doc/html/syslog-ng

	${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.netbsd \
		${PKG_SYSCONFDIR}/syslog-ng

.include "../../wip/libol/buildlink3.mk"
#.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
