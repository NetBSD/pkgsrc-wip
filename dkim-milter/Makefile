# $NetBSD: Makefile,v 1.31 2008/03/23 13:06:53 jukka Exp $

DISTNAME=	dkim-milter-2.5.1
#PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dkim-milter/}

MAINTAINER=	j+pkgsrc@salmi.ch
HOMEPAGE=	http://sourceforge.net/projects/dkim-milter/
COMMENT=	Open source DKIM filter software from Sendmail, Inc.

BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0
BUILDLINK_API_DEPENDS.openssl+=		openssl>=0.9.8

LICENSE=		sendmail-open-source-license
MAKE_ENV+=		M4=${M4:Q}
RCD_SCRIPTS=		dkim-milter
USE_BUILTIN.libmilter=	no
USE_TOOLS+=		gm4
PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	post-patch
SUBST_FILES.libs=	site.config.m4.dist dkim-filter/Makefile.m4 \
			devtools/M4/header.m4
SUBST_SED.libs=		-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g'
SUBST_SED.libs+=	-e 's|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD@|${BUILDLINK_PREFIX.pthread}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD_LDFLAGS@|${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|g'
SUBST_MESSAGE.libs=	Fixing makefile references.

# Rename dkim-filter to dkim-milter.
# tv@ has done this when importing the original dk-milter package from
# pkgsrc-wip to pkgsrc, hence we continue this tradition.
SUBST_CLASSES+=		rename
SUBST_STAGE.rename=	post-build
SUBST_FILES.rename=	dkim-filter/dkim-filter.conf.5 \
			dkim-filter/dkim-filter.conf.sample \
			dkim-filter/dkim-filter.8 \
			dkim-filter/dkim-stats.8
SUBST_SED.rename=	-e 's|dkim-filter|dkim-milter|g'
SUBST_MESSAGE.rename=	Renaming dkim-filter to dkim-milter

INSTALLATION_DIRS=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			bin sbin share/doc/dkim-milter/libdkim \
			share/examples/dkim-milter

EGDIR=			${PREFIX}/share/examples/dkim-milter
CONF_FILES=		${EGDIR}/dkim-milter.conf.sample \
			${PKG_SYSCONFDIR}/dkim-milter.conf

pre-configure:
	mv ${WRKSRC}/site.config.m4.dist ${WRKSRC}/devtools/Site/site.config.m4

do-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

do-install: arlib-install stats-install
	cd ${WRKSRC}/obj.`uname -s`.`uname -r`.`uname -m`; \
	${INSTALL_PROGRAM} dkim-filter/dkim-testkey ${DESTDIR}${PREFIX}/bin; \
	${INSTALL_PROGRAM} dkim-filter/dkim-testssp ${DESTDIR}${PREFIX}/bin; \
	${INSTALL_PROGRAM} dkim-filter/dkim-filter ${DESTDIR}${PREFIX}/sbin/dkim-milter; \
	${INSTALL_LIB} libdkim/libdkim.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/dkim-filter/dkim-genkey.sh ${DESTDIR}${PREFIX}/bin/dkim-genkey
	${INSTALL_MAN} ${WRKSRC}/dkim-filter/dkim-filter.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/dkim-milter.conf.5
	${INSTALL_MAN} ${WRKSRC}/dkim-filter/dkim-filter.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/dkim-milter.8
	${INSTALL_MAN} ${WRKSRC}/dkim-filter/dkim-genkey.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/dkim-filter/dkim-testkey.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/dkim-filter/dkim-testssp.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-hoffman-dac-vbr-02.txt ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-ietf-dkim-deployment-01.txt ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-ietf-dkim-overview-09.txt ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-ietf-dkim-ssp-03.txt ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-kucherawy-sender-auth-header-14.txt ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/rfc4686.txt ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/rfc4871.txt ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/rfc5016.txt ${DESTDIR}${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/dkim-filter/dkim-filter.conf.sample ${DESTDIR}${PREFIX}/share/examples/dkim-milter/dkim-milter.conf.sample
	cd ${WRKSRC}/libdkim/docs; for file in *.html; do \
	${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/share/doc/dkim-milter/libdkim; done

.include "options.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
