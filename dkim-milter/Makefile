# $NetBSD: Makefile,v 1.19 2007/10/07 13:27:34 jukka Exp $

DISTNAME=	dkim-milter-2.3.0
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
			sbin share/doc/dkim-milter/libdkim \
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
	${INSTALL_PROGRAM} dkim-filter/dkim-filter ${PREFIX}/sbin/dkim-milter; \
	${INSTALL_LIB} libdkim/libdkim.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/dkim-filter/dkim-filter.conf.5 ${PREFIX}/${PKGMANDIR}/man5/dkim-milter.conf.5
	${INSTALL_MAN} ${WRKSRC}/dkim-filter/dkim-filter.8 ${PREFIX}/${PKGMANDIR}/man8/dkim-milter.8
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-hoffman-dac-vbr-01.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-ietf-dkim-overview-05.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-ietf-dkim-ssp-01.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-ietf-dkim-ssp-requirements-05.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-kucherawy-sender-auth-header-07.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/rfc4686.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/rfc4871.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/dkim-filter/dkim-filter.conf.sample ${PREFIX}/share/examples/dkim-milter/dkim-milter.conf.sample
	cd ${WRKSRC}/libdkim/docs; for file in *.html; do \
	${INSTALL_DATA} $$file ${PREFIX}/share/doc/dkim-milter/libdkim; done

.include "options.mk"
# XXX this should be switched once OpenSSL >=0.9.8 is in pkgsrc
.include "../../wip/openssl/buildlink3.mk"
#.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
