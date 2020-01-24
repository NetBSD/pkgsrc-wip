# $NetBSD: Makefile,v 1.4 2014/08/13 20:21:06 thomasklausner Exp $
#

DISTNAME=	logwatch-7.4.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=logwatch/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://logwatch.sourceforge.net/
COMMENT=	Customizable log analysis system
LICENSE=	mit

DEPENDS=	p5-MIME-Base64>=3.13:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Sys-CPU>=0.54:../../sysutils/p5-Sys-CPU
DEPENDS+=	p5-Sys-MemInfo>=0.91:../../wip/p5-Sys-MemInfo

NO_BUILD=		yes
USE_TOOLS+=		pax perl:run
REPLACE_PERL+=		lib/Logwatch.pm scripts/logwatch.pl \
			scripts/services/amavis \
			scripts/services/cisco \
			scripts/services/http-error \
			scripts/services/mysql \
			scripts/services/postfix \
			scripts/services/spamassassin

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	logwatch.8 scripts/logwatch.pl \
			HOWTO-Customize-LogWatch README \
			scripts/services/clam-update
SUBST_SED.path=		-e "s|/usr/share/logwatch|${PREFIX}/share/logwatch|g"
SUBST_SED.path+=	-e "s|/etc/logwatch|${PREFIX}/etc/logwatch|g"
SUBST_SED.path+=	-e "s|/usr/share/doc/logwatch-.|${PREFIX}/share/doc/logwatch|g"
SUBST_MESSAGE.path=	Fixing logwatch paths.

PKG_SYSCONFSUBDIR=	logwatch
EGDIR=			${PREFIX}/share/examples/logwatch
OWN_DIRS=		${PKG_SYSCONFDIR}/conf
OWN_DIRS+=		${PKG_SYSCONFDIR}/conf/services
CONF_FILES+=		${EGDIR}/conf/ignore.conf ${PKG_SYSCONFDIR}/conf/ignore.conf
CONF_FILES+=		${EGDIR}/conf/logwatch.conf ${PKG_SYSCONFDIR}/conf/logwatch.conf
.for service in secure sshd
CONF_FILES+=		${EGDIR}/conf/services/${service}.conf ${PKG_SYSCONFDIR}/conf/services/${service}.conf
.endfor

INSTALLATION_DIRS+=	${PKGMANDIR}/man8 sbin share/doc/logwatch \
			share/logwatch/default.conf share/logwatch/scripts share/logwatch/lib \
			share/logwatch/dist.conf/logfiles \
			share/logwatch/dist.conf/services
INSTALLATION_DIRS+=	${EGDIR:S|${PREFIX}/||}/conf ${EGDIR:S|${PREFIX}/||}/conf/services

.include "../../mk/bsd.prefs.mk"

post-extract:
	${CP} -r ${FILESDIR}/host ${WRKSRC}
	${RM} -r ${WRKSRC}/host/CVS ${WRKSRC}/host/*/CVS ${WRKSRC}/host/*/*/CVS
.if exists(${FILESDIR}/dist.conf/${OPSYS})
	${CP} -r ${FILESDIR}/dist.conf/${OPSYS} ${WRKSRC}/dist.conf
	${RM} -r ${WRKSRC}/dist.conf/CVS ${WRKSRC}/dist.conf/*/CVS
.else
	${MKDIR} ${WRKSRC}/dist.conf
.endif

pre-install:
	${RM} ${WRKSRC}/scripts/services/*.orig

do-install:
	cd ${WRKSRC}/conf && pax -rw . ${DESTDIR}${PREFIX}/share/logwatch/default.conf
	cd ${WRKSRC}/dist.conf && pax -rw . ${DESTDIR}${PREFIX}/share/logwatch/dist.conf
	cd ${WRKSRC}/host && pax -rw ./conf ${DESTDIR}${PREFIX}/etc/logwatch
	cd ${WRKSRC}/host && pax -rw ./conf ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/scripts && pax -rw . ${DESTDIR}${PREFIX}/share/logwatch/scripts
	cd ${WRKSRC}/lib && pax -rw . ${DESTDIR}${PREFIX}/share/logwatch/lib
	${LN} -s ${DESTDIR}${PREFIX}/share/logwatch/scripts/logwatch.pl ${DESTDIR}${PREFIX}/sbin/logwatch
	${INSTALL_MAN} ${WRKSRC}/logwatch.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/HOWTO-Customize-LogWatch ${DESTDIR}${PREFIX}/share/doc/logwatch
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/logwatch
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/logwatch

.include "../../mk/bsd.pkg.mk"
