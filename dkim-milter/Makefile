# $NetBSD: Makefile,v 1.4 2007/08/04 06:27:04 jukka Exp $

DISTNAME=	dkim-milter-2.0.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dkim-milter/}

MAINTAINER=	j+pkgsrc@salmi.ch
HOMEPAGE=	http://sourceforge.net/projects/dkim-milter/
COMMENT=	Open source DKIM filter software from Sendmail, Inc

BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0
BUILDLINK_API_DEPENDS.openssl+=		openssl>=0.9.8

LICENSE=		no-profit
MAKE_ENV+=		M4=${M4:Q}
RCD_SCRIPTS=		dkim-milter
USE_BUILTIN.libmilter=	no
USE_TOOLS+=		gm4

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	pre-configure
SUBST_FILES.libs=	site.config.m4.dist dkim-filter/Makefile.m4
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
			dkim-filter/dkim-filter.8
SUBST_SED.rename=	-e 's|dkim-filter|dkim-milter|g'
SUBST_MESSAGE.rename=	Renaming -filter to -milter

INSTALLATION_DIRS=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			sbin share/doc/dkim-milter share/examples/dkim-milter

EGDIR=			${PREFIX}/share/examples/dkim-milter
CONF_FILES=		${EGDIR}/dkim-milter.conf.sample \
			${PKG_SYSCONFDIR}/dkim-milter.conf

do-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

do-install:
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
	${INSTALL_DATA} ${WRKSRC}/draft-ietf-dkim-ssp-00.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/draft-ietf-dkim-ssp-requirements-04.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/rfc4686.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/rfc4871.txt ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/dkim-filter/dkim-filter.conf.sample ${PREFIX}/share/examples/dkim-milter/dkim-milter.conf.sample

.include "options.mk"
# XXX this should be switched once OpenSSL >=0.9.8 is in pkgsrc
.include "../../wip/openssl/buildlink3.mk"
#.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
