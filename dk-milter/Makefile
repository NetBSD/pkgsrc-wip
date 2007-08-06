# $NetBSD: Makefile,v 1.7 2007/08/06 11:17:39 jukka Exp $

DISTNAME=	dk-milter-0.6.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dk-milter/}

MAINTAINER=	j+pkgsrc@salmi.ch
HOMEPAGE=	http://sourceforge.net/projects/dk-milter/
COMMENT=	Open source DomainKeys filter software from Sendmail, Inc.

BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0

LICENSE=		no-profit
MAKE_ENV+=		M4=${M4:Q}
RCD_SCRIPTS=		dk-milter
USE_BUILTIN.libmilter=	no
USE_TOOLS+=		gm4

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	post-patch
SUBST_FILES.libs=	site.config.m4.dist dk-filter/Makefile.m4
SUBST_SED.libs=		-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g'
SUBST_SED.libs+=	-e 's|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD@|${BUILDLINK_PREFIX.pthread}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD_LDFLAGS@|${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|g'
SUBST_MESSAGE.libs=	Fixing makefile references.

# Rename dk-filter to dk-milter.
# tv@ has done this when importing the original dk-milter package from
# pkgsrc-wip to pkgsrc, hence we continue this tradition.
SUBST_CLASSES+=		rename
SUBST_STAGE.rename=	post-build
SUBST_FILES.rename=	dk-filter/dk-filter.8
SUBST_SED.rename=	-e 's|dk-filter|dk-milter|g'
SUBST_MESSAGE.rename=	Renaming dk-filter to dk-milter

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/dk-milter

pre-configure:
	mv ${WRKSRC}/site.config.m4.dist ${WRKSRC}/devtools/Site/site.config.m4

do-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

do-install:
	cd ${WRKSRC}/obj.`uname -s`.`uname -r`.`uname -m`; \
	${INSTALL_PROGRAM} dk-filter/dk-filter ${PREFIX}/sbin/dk-milter; \
	${INSTALL_LIB} libdk/libdk.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/dk-filter/dk-filter.8 ${PREFIX}/${PKGMANDIR}/man8/dk-milter.8
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/rfc4870.txt ${PREFIX}/share/doc/dk-milter

.include "options.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
