# $NetBSD: Makefile,v 1.20 2010/04/21 10:44:50 fhajny Exp $

DISTNAME=	dk-milter-1.0.2
#PKGREVISION=	1
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dk-milter/}

MAINTAINER=	j+pkgsrc@salmi.ch
HOMEPAGE=	http://sourceforge.net/projects/dk-milter/
COMMENT=	Open source DomainKeys filter software from Sendmail, Inc.
LICENSE=	sendmail-open-source-license

MAKE_ENV+=		M4=${M4:Q}
RCD_SCRIPTS=		dk-milter
USE_BUILTIN.libmilter=	no
USE_TOOLS+=		gm4
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	post-patch
SUBST_FILES.libs=	site.config.m4.dist dk-filter/Makefile.m4 \
			devtools/M4/header.m4
SUBST_SED.libs=		-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g'
SUBST_SED.libs+=	-e 's|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD@|${BUILDLINK_PREFIX.pthread}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD_LDFLAGS@|${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|g'
.if ${OPSYS} == SunOS
SUBST_SED.libs+=        -e 's|-lrt|-lrt -lresolv|g'
.endif
SUBST_MESSAGE.libs=	Fixing makefile references.

# Rename dk-filter to dk-milter.
# tv@ has done this when importing the original dk-milter package from
# pkgsrc-wip to pkgsrc, hence we continue this tradition.
SUBST_CLASSES+=		rename
SUBST_STAGE.rename=	post-build
SUBST_FILES.rename=	dk-filter/dk-filter.8
SUBST_SED.rename=	-e 's|dk-filter|dk-milter|g'
SUBST_MESSAGE.rename=	Renaming dk-filter to dk-milter

INSTALLATION_DIRS=	lib ${PKGMANDIR}/man8 sbin share/doc/dk-milter/libdk

pre-configure:
	mv ${WRKSRC}/site.config.m4.dist ${WRKSRC}/devtools/Site/site.config.m4

do-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

do-install:
	cd ${WRKSRC}/obj.`uname -s`.`uname -r`.`uname -m`; \
	${INSTALL_PROGRAM} dk-filter/dk-filter ${DESTDIR}${PREFIX}/sbin/dk-milter; \
	${INSTALL_LIB} libdk/libdk.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/dk-filter/dk-filter.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/dk-milter.8
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${DESTDIR}${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${DESTDIR}${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${DESTDIR}${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/rfc4870.txt ${DESTDIR}${PREFIX}/share/doc/dk-milter
	cd ${WRKSRC}/libdk/docs; for file in *.html; do \
	${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/share/doc/dk-milter/libdk; done

.include "options.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
