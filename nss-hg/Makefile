# $NetBSD: Makefile,v 1.3 2015/01/24 16:48:48 thomasklausner Exp $

# necessary because hg-package.mk would override it
PKGNAME=		nss-${NSS_RELEASE}
DISTNAME=		nss-${NSS_RELEASE}
# see lib/nss/nss.h
NSS_RELEASE=		3.29.0beta1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_MOZILLA_ALL:=security/nss/releases/NSS_${NSS_MAJOR_VERSION}_${NSS_MINOR_VERSION}_RTM/src/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mozilla.org/projects/security/pki/nss/
COMMENT=		Libraries to support development of security-enabled applications (hg version)
LICENSE=		mpl-2.0

HG_REPOSITORIES=	nss
HG_REPO.nss=		https://hg.mozilla.org/projects/nss
WRKSRC=			${WRKDIR}/nss
#WRKSRC=		${WRKDIR}

USE_LANGUAGES=		c c++

BUILDLINK_TRANSFORM+=	rm:-Werror

# wants to use zlib before making sure it's built
MAKE_JOBS_SAFE=		no

CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}js/src/configure
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}configure

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		gmake perl pax pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SUBST_CLASSES+=			exec_path
SUBST_STAGE.exec_path=		pre-configure
SUBST_MESSAGE.exec_path=	Fixing @executable_path
SUBST_FILES.exec_path=		coreconf/Darwin.mk
SUBST_SED.exec_path=		-e 's,@executable_path,${PREFIX}/lib/nss,g'
.endif

.if ${OPSYS} == "Linux"
MAKE_ENV+=	FREEBL_NO_DEPEND=0
.endif

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX:Q}

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Mgcc)
MAKE_ENV+=	NS_USE_GCC=YES
.endif

.for platform in ${LP64PLATFORMS}
.  if ${MACHINE_PLATFORM:M${platform}}
MAKE_ENV+=	USE_64=1
.  endif
.endfor

MAKE_ENV+=	BUILD_OPT=1
#MAKE_ENV+=	OPTIMIZER=${CFLAGS:Q}
MAKE_ENV+=	INCLUDES=-I${BUILDLINK_PREFIX.nspr}/include/nspr
MAKE_ENV+=	NSS_USE_SYSTEM_SQLITE=1
MAKE_ENV+=	EXTRA_SHARED_LIBS="-Wl,-R${BUILDLINK_PREFIX.nspr}/lib/nspr -Wl,-R,${PREFIX}/lib/nss -L${BUILDLINK_PREFIX.nspr}/lib/nspr -lplc4 -lplds4 -lnspr4"

NSS_MAJOR_VERSION=	${NSS_RELEASE:C/\.[0-9.]*//}
NSS_MINOR_VERSION=	${NSS_RELEASE:S/3.//:C/\.[0-9]*//}
NSS_PATCH_VERSION=	${NSS_RELEASE:C/[0-9.]*\.//}

SUBST_CLASSES+=		config
SUBST_SED.config+=	-e "s,@PREFIX@,${PREFIX},g"
SUBST_SED.config+=	-e "s,@NSS_MAJOR_VERSION@,${NSS_MAJOR_VERSION},"
SUBST_SED.config+=	-e "s,@NSS_MINOR_VERSION@,${NSS_MINOR_VERSION},"
SUBST_SED.config+=	-e "s,@NSS_PATCH_VERSION@,${NSS_PATCH_VERSION},"
SUBST_SED.config+=	-e "s!@COMPILER_RPATH_FLAG@!${COMPILER_RPATH_FLAG}!"
SUBST_SED.config+=	-e "s,@PTHREAD@,${BUILDLINK_LIBS.pthread:Q},"
SUBST_STAGE.config=	pre-build
SUBST_MESSAGE.config=	Preparing *-config files.
SUBST_FILES.config+=	nss.pc nss-config

INSTALLATION_DIRS=	bin include/nss lib/nss lib/pkgconfig
DIST=	${WRKDIR}/dist

post-extract:
	find ${WRKSRC} -type f | xargs ${CHMOD} 644
	find ${WRKSRC} -type d | xargs ${CHMOD} 755
	${CP} ${FILESDIR}/nss.pc.in ${WRKSRC}/nss.pc
	${CP} ${FILESDIR}/nss-config.in ${WRKSRC}/nss-config

do-install:
	(cd ${DIST}/public && pax -Lrw . ${DESTDIR}${PREFIX}/include/nss/ )
	(cd ${DIST}/*_OPT.OBJ/lib && \
		pax -Lrw *.${SO_SUFFIX} ${DESTDIR}${PREFIX}/lib/nss/ )
	${INSTALL_LIB} ${DIST}/*_OPT.OBJ/lib/libcrmf.a \
		${DESTDIR}${PREFIX}/lib/nss/
	${INSTALL_DATA} ${WRKSRC}/nss.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/nss.pc
	${INSTALL_SCRIPT} ${WRKSRC}/nss-config ${DESTDIR}${PREFIX}/bin/nss-config

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/nspr-hg/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
