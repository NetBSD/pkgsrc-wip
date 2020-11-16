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

PLIST_SUBST+=	MODNAME=${MODNAME}
PLIST_SUBST+=	PKGMODNAME=${PKGMODNAME}
PLIST_SUBST+=	SHLIB_SUFFIX=${SHLIB_SUFFIX}
PLIST_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

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
	${MKDIR} ${DESTDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/${MODNAME}.unit.so \
		${DESTDIR}${PREFIX}/libexec/unit/modules/


.endif  # PHPEXT_MK
