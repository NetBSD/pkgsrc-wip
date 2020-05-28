# $NetBSD$

PKGNAME=	ldc-0.17.6
PKGREVISION=	1
DISTNAME=	${PKGNAME_NOREV}-src
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=ldc-developers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ldc-developers/ldc/
COMMENT=	D compiler based on LLVM
LICENSE=	modified-bsd					\
		AND (artistic OR gnu-gpl-v1)			\
		AND (artistic OR gnu-gpl-v2 OR gnu-gpl-v3)	\
		AND gnu-lgpl-v2.1				\
		AND modified-bsd				\
		AND boost-license
#TODO: The modified-bsd two lines above should be
# University of Illinois Open Source License.
# They are similar, but I am not sure if they are equivalent.

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH}

EGDIR=	${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=	${EGDIR}/ldc2.conf ${PKG_SYSCONFDIR}/ldc2.conf

GENERATE_PLIST+=	cd ${DESTDIR}${PREFIX}; \
                        ${FIND} * \( -type f -or -type l \) | ${SORT};

post-install:
	${MKDIR} -p ${DESTDIR}${EGDIR}	\
		&& ${MV} ${DESTDIR}${PREFIX}/etc/ldc2.conf	\
			${DESTDIR}${EGDIR}

.include "../../wip/libLLVM38/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
