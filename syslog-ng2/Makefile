# $NetBSD: Makefile,v 1.5 2012/10/07 16:23:22 asau Exp $
#

PKGVERSION=	2.0.0
DISTNAME=	syslog-ng-${PKGVERSION}
PKGNAME=	syslog-ng2-${PKGVERSION}

CATEGORIES=	sysutils net
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/sources/stable/src/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.balabit.com/products/syslog-ng/
COMMENT=	Syslog-ng embodies the next generation of logging systems

CONFLICTS=	syslog-ng-[0-9]*

PKG_DESTDIR_SUPPORT=	none

USE_TOOLS+=	pkg-config pax

GNU_CONFIGURE=	yes

RCD_SCRIPTS=		syslogng
PKG_SYSCONFSUBDIR=	syslog-ng

EGDIR=			${PREFIX}/share/examples/syslog-ng
DOCDIR=			${PREFIX}/share/doc/syslog-ng

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	doc/man/syslog-ng.8 doc/man/syslog-ng.conf.5 contrib/syslog2ng
SUBST_SED.conf=		-e "s|/etc/syslog-ng|${PKG_SYSCONFDIR}|g"
SUBST_SED.conf+=	-e "s|/usr/bin/awk|${AWK}|g"
SUBST_MESSAGE.conf=	Fixing configuration file paths.

pre-build:
	cd ${WRKSRC}/doc/reference && \
		gzip -d -c ${WRKSRC}/doc/reference/syslog-ng.html.tar.gz | pax -r

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/syslog-ng
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}

	${INSTALL_DATA} ${WRKSRC}/contrib/syslog-ng.conf.doc ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/syslog-ng.conf.sample ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/syslog-ng.conf.solaris ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/syslog-ng.conf.HP-UX ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/syslog-ng.conf.RedHat ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/syslog-ng.conf.SunOS ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/syslog-ng.conf.HP-UX ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/syslog-ng.conf ${EGDIR}/syslog-ng.conf.debian
	${INSTALL_DATA} ${WRKSRC}/debian/syslog-ng.logrotate ${EGDIR}/syslog-ng.logrotate.debian
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/syslog2ng ${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/doc/reference/syslog-ng.html/*.html ${DOCDIR}


.include "../../wip/eventlog/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
