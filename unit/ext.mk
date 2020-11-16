# $NetBSD$
#
# NGINX Unit extension package framework, for bundled extensions.
#
# Just include this file, define MODNAME, define PKGREVISION if necessary,
# add dependencies, and add the appropriate --with-configure-arg, then include
# bsd.pkg.mk.
#
# Original idea comes from lang/php/ext.mk.

.if !defined(UNITEXT_MK)
UNITEXT_MK=	defined

.include "../../www/unit/unitversion.mk"

DISTINFO_FILE=	${.CURDIR}/../../www/unit/distinfo
PATCHDIR=	${.CURDIR}/../../www/unit/patches

PKGMODNAME?=	${MODNAME}.unit

PLIST_SUBST+=	PKGMODNAME=${MODNAME}.unit
PLIST_SUBST+=	SHLIB_SUFFIX=${SHLIB_SUFFIX}
PLIST_SUBST+=	UNIT_EXTENSION_DIR=${UNIT_EXTENSION_DIR}

PLIST_SRC+=	${.CURDIR}/../../www/unit/PLIST.module

.if ${OBJECT_FMT} == "SOM"
SHLIB_SUFFIX=		sl
.else
SHLIB_SUFFIX=		so
.endif

do-build: do-module-build

do-module-build:
	cd ${WRKSRC} && ${MAKE} ${MODNAME}

do-install: do-module-install

do-module-install:
	${MKDIR} ${DESTDIR}${PREFIX}/${UNIT_EXTENSION_DIR}
	${INSTALL_LIB} ${WRKSRC}/build/${PKGMODNAME}.${SHLIB_SUFFIX} \
		${DESTDIR}${PREFIX}/${UNIT_EXTENSION_DIR}

.endif  # UNITEXT_MK

.include "${.CURDIR}/../../www/unit/common.mk"
